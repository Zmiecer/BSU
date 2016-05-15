package by.bsu.zmiecer.game;

import by.bsu.zmiecer.IO.Input;
import by.bsu.zmiecer.display.Display;
import by.bsu.zmiecer.game.entity.*;
import by.bsu.zmiecer.graphics.TextureAtlas;
import by.bsu.zmiecer.utils.Time;

import java.awt.*;
import java.util.ArrayList;
import java.util.Stack;
import java.util.concurrent.ThreadLocalRandom;

/**
 * Created by Zmiecer on 06.05.2016.
 */
public class Game implements Runnable {

    public static final int     WIDTH           = 640; // 20 тайлов
    public static final int     HEIGHT          = 512; // 16 тайлов
    public static final String  TITLE           = "Tanks";

    public static final int     CLEAR_COLOR     = 0xff000000;
    //public static final int     NUM_BUFFERS     = 3;

    public static final float   UPDATE_RATE     = 60.0f;
    public static final float   UPDATE_INTERVAL = Time.SECOND/UPDATE_RATE;
    public static final long    IDLE_TIME       = 1;

    public static final String  ATLAS_FILE_NAME = "texture_atlas1.png";

    private static final String     NORTH       = "NORTH";
    private static final String     WEST        = "WEST";
    private static final String     SOUTH       = "SOUTH";
    private static final String     EAST        = "EAST";

    private boolean             running;
    private Thread              gameThread;
    private Graphics2D          graphics;
    private Input               input;
    private static TextureAtlas        atlas;
    private static Player       player;
    private static ArrayList<Entity>   entities;
    private static Stack<Entity> destroyed = new Stack<>();
    private static Stack<Entity> added = new Stack<>();
    public static long          respawnTime     = (int)(UPDATE_RATE * 30);
    public static boolean       gameOver = false;

    public static final float    SCALE          = 2;


    public Game()
    {
        running = false;
        Display.create(WIDTH, HEIGHT, TITLE, CLEAR_COLOR /*, NUM_BUFFERS*/);
        graphics = Display.getGraphics();
        input = new Input();
        Display.addInputListener(input);
        atlas = new TextureAtlas(ATLAS_FILE_NAME);
        player = new Player(7.5f * Entity.SPRITE_SCALE * Game.SCALE, 15 * Entity.SPRITE_SCALE * Game.SCALE, 0, atlas);



        entities = new ArrayList<>();
        addEntity(player);
        createFirstEntities();

    }

    public synchronized void start()
    {
        if(running)
            return;

        running = true;
        gameThread = new Thread(this);
        gameThread.start();
    }

    public synchronized void stop()
    {
        if(!running)
            return;

        running = false;


        try
        {
            gameThread.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        cleanUp();
    }

    private void update() // Физика
    {
        for (Entity e : entities) {
            e.update(input);
        }
        for (Entity e1 : entities) {
            for (Entity e2 : entities) {
                shot(e1, e2);
                }
        }
        for (Entity e : destroyed) {
            entities.remove(e);
        }
        destroyed.clear();
        entities.addAll(added);
        added.clear();
    }

    // Рисование
    private void render()
    {
        Display.clear();
        for (Entity e : entities)
        {
            e.render(graphics);
        }
        Display.swapBuffers();
    }


    @Override
    public void run()
    {
        int fps = 0;
        int upd = 0;
        int updl = 0;

        long count = 0;

        float delta = 0;

        long lastTime = Time.get();
        while (running)
        {
            long now = Time.get();
            long elapsedTime = now - lastTime;
            lastTime = now;

            count += elapsedTime;

            boolean render = false;
            delta += ( elapsedTime / UPDATE_INTERVAL);
            while(delta > 1) // while, а не if на случай пропуска update
            {
                update();
                upd++;
                delta--;
                if(render)
                {
                    updl++;
                }
                else
                {
                    render = true;
                }
            }

            if (render)
            {
                render();
                fps++;
            }
            else
            {
                try
                {
                    Thread.sleep(IDLE_TIME);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }

            if (count >= Time.SECOND)
            {
                Display.setTitle(TITLE + " || fps: " + fps + " | upd: " + upd + " | updl: " + updl);
                upd = 0;
                fps = 0;
                updl = 0;
                count = 0;
            }
        }

    }

    private void cleanUp()
    {
        Display.destroy();
    }

    private void shot(Entity e1, Entity e2)
    {
        if(e1.type == EntityType.Bullet)
        {
            if (Math.abs(e1.getX() + 4*SCALE - (e2.getX() + 8*SCALE)) < 8*SCALE && Math.abs(e1.getY() + 4*SCALE - (e2.getY() + 8*SCALE)) < 8*SCALE)
            {
                if(e2.type == EntityType.Enemy)
                {
                    destroy(e1);
                    e2.shot();
                }
                else if (e2.type == EntityType.Player)
                {
                    gameOver();
                    // stop();
                }
                else if (e2.type == EntityType.Bullet && e1 != e2)
                {
                    if (Math.abs(e1.getX() + 4*SCALE - (e2.getX() + 4*SCALE)) < 4*SCALE && Math.abs(e1.getY() + 4*SCALE - (e2.getY() + 4*SCALE)) < 4*SCALE)
                    {
                        destroy(e1);
                        destroy(e2);
                    }
                }
            }
        }
        else if (e1.type == EntityType.Enemy)
        {
            if (Math.abs(e1.getX() + 8*SCALE - (e2.getX() + 8*SCALE)) < 8*SCALE && Math.abs(e1.getY() + 8*SCALE - (e2.getY() + 8*SCALE)) < 8*SCALE) {
                if (e2.type == EntityType.Enemy) {
                    int dir = e1.getHeading().toInt();
                    dir += 2;
                    dir %= 4;
                    e1.setDir(dir);
                    dir = e2.getHeading().toInt();
                    dir += 2;
                    dir %= 4;
                    e2.setDir(dir);
                } else if (e2.type == EntityType.Player) {
                    int dir = e1.getHeading().toInt();
                    dir += 2;
                    dir %= 4;
                    e1.setDir(dir);
                }
            }
        }
    }

    private void gameOver()
    {
        //destroyed.addAll(entities);
        Player.alive = false;
        //destroyed.addAll(entities);
        //stop();
    }

    public static void destroy(Entity e)
    {
        destroyed.push(e);
    }

    public static void destroyAll()
    {
        destroyed.addAll(entities);
    }

    public static void addEntity(Entity e)
    {
        added.push(e);
    }

    private static final float RESPAWN_1_X = 0;
    private static final float RESPAWN_2_X = 9.5f * Entity.SPRITE_SCALE * SCALE;
    private static final float RESPAWN_3_X = 19 * Entity.SPRITE_SCALE * SCALE;

    private void respawn()
    {
        int respawn = ThreadLocalRandom.current().nextInt(0, 2 + 1);
        int level = ThreadLocalRandom.current().nextInt(0, 7 + 1);
        float x = 0;
        switch (respawn)
        {
            case 0:
                x = RESPAWN_1_X;
                break;
            case 1:
                x = RESPAWN_2_X;
                break;
            case 2:
                x = RESPAWN_3_X;
                break;
        }
        Enemy enemy = new Enemy(x, 0, level, atlas);
        added.push(enemy);
    }

    public static void createFirstEntities()
    {
        int level = ThreadLocalRandom.current().nextInt(0, 7 + 1);
        Enemy enemy = new Enemy(RESPAWN_1_X, 0, level, atlas);
        addEntity(enemy);
        level = ThreadLocalRandom.current().nextInt(0, 7 + 1);
        enemy = new Enemy(RESPAWN_2_X, 0, level, atlas);
        addEntity(enemy);
        level = ThreadLocalRandom.current().nextInt(0, 7 + 1);
        enemy = new Enemy(RESPAWN_3_X, 0, level, atlas);
        addEntity(enemy);
    }
}
