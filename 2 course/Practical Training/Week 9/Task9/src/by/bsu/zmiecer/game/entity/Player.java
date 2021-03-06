package by.bsu.zmiecer.game.entity;

import by.bsu.zmiecer.IO.Input;
import by.bsu.zmiecer.game.Game;
import by.bsu.zmiecer.graphics.TextureAtlas;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by Zmiecer on 09.05.2016.
 */
public class Player extends Tank
{
//    private static float x;
//    private static float y;

    public static boolean alive = true;

    private boolean moving = false;

    public Player(float x, float y, int level, TextureAtlas atlas)
    {
        super(EntityType.Player, x, y, level, atlas);
//        Player.x = x;
//        Player.y = y;

        spriteMap = new HashMap<>();


        north = new Heading(0,  0,  1,  1, NORTH);
        west = new Heading( 2,  0,  1,  1, WEST);
        south = new Heading(4,  0,  1,  1, SOUTH);
        east = new Heading( 6,  0,  1,  1, EAST);

        heading = north;

        setLevel(level);
        this.speed = 1.5f;
        elapsedTime = 2*60;
    }

    public void update(Input input)
    {
        float newX = x; //Player.x;
        float newY = y; //Player.y;

        if(alive)
        {
            if (input.getKey(KeyEvent.VK_W)) {
                newY -= speed;
                heading = north;
                moving = true;
            } else if (input.getKey(KeyEvent.VK_A)) {
                newX -= speed;
                heading = west;
                moving = true;
            } else if (input.getKey(KeyEvent.VK_S)) {
                newY += speed;
                heading = south;
                moving = true;
            } else if (input.getKey(KeyEvent.VK_D)) {
                newX += speed;
                heading = east;
                moving = true;
            }
            if (newX - x == 0 && newY - y == 0)
                moving = false;

            if (input.getKey(KeyEvent.VK_SPACE)) {
                if (elapsedTime > 1.5 * 60) {
                    shoot();
                    elapsedTime = 0;
                }
            }
        }
        else if (!Game.gameOver)
        {
            //Game.added.push(new GameOverTile);
            Game.gameOver = true;
        }
        if (input.getKey(KeyEvent.VK_R) && elapsedTime > 5 * 60)
        {
            Game.gameOver = false;
            Player.alive = true;
            newX = 7.5f * Entity.SPRITE_SCALE * Game.SCALE;
            newY = 15 * Entity.SPRITE_SCALE * Game.SCALE;
            heading = north;
            Game.destroyAll();
            Game.addEntity(this);
            Game.createFirstEntities();
            elapsedTime = 0;
        }

        if (newX < 0)
        {
            newX = 0;
        }
        else if (newX >= Game.WIDTH - SPRITE_SCALE*scale)
        {
            newX = Game.WIDTH - SPRITE_SCALE*scale;
        }

        if (newY < 0)
        {
            newY = 0;
        }
        else if (newY >= Game.HEIGHT - SPRITE_SCALE*scale)
        {
            newY = Game.HEIGHT - SPRITE_SCALE*scale;
        }

//        Player.x = newX;
//        Player.y = newY;
        x = newX;
        y = newY;

        elapsedTime++;
    }

//    public static float getPX()
//    {
//        return x;
//    }
//
//    public static float getPY()
//    {
//        return y;
//    }

    @Override
    public void render(Graphics2D g) {
        spriteMap.get(heading).render(g, x, y, moving);
    }

    @Override
    public void setLevel(int level)
    {
        super.setLevel(level);
        if(level == 0)
            bulletSpeed = 0;
        else
            bulletSpeed = 1;

        switch (level%8)
        {
            case 0:
            case 3:
            case 7:
                speed = 1.5f;
                break;
            case 1:
            case 2:
            case 4:
            case 6:
                speed = 2f;
                break;
            case 5:
                speed = 2.5f;
                break;
        }
    }
}
