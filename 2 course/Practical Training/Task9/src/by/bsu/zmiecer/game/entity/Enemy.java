package by.bsu.zmiecer.game.entity;

import by.bsu.zmiecer.IO.Input;
import by.bsu.zmiecer.game.Game;
import by.bsu.zmiecer.graphics.TextureAtlas;

import java.awt.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.concurrent.ThreadLocalRandom;

/**
 * Created by Zmiecer on 09.05.2016.
 */
public class Enemy extends Tank
{
    public Enemy(float x, float y, int level, TextureAtlas atlas)
    {
        super(EntityType.Enemy, x, y, level, atlas);

        spriteMap = new HashMap<>();


        north = new Heading(8,  0,  2,  1,  NORTH);
        west = new Heading(10,  0,  2,  1,  WEST);
        south = new Heading(12, 0,  2,  1,  SOUTH);
        east = new Heading(14,  0,  2,  1,  EAST);
        spritesPerHeading = 2;


        heading = south;

        setLevel(level);

        elapsedTime = 0;
        fromChangeDirTime = 0;
        fromShootTime = 0;
        changeDirTime = ThreadLocalRandom.current().nextInt(2, 4 + 1);
        shootTime = ThreadLocalRandom.current().nextInt(2, 4 + 1);
        alive = true;
    }


    private int fromChangeDirTime;
    private int changeDirTime;
    private int shootTime;
    private int fromShootTime;
    private boolean alive;

    @Override
    public void update(Input input)
    {
        if(alive) {
            float newX = x;
            float newY = y;

            //Автоматический алгоритм движения
            if (elapsedTime < Game.respawnTime / 3) {
                // moveRandom
                moveRandom();
            } else if (elapsedTime < 2 * Game.respawnTime / 3) {
                // moveToPlayer
                moveRandom();
                //moveToPlayer();
            } else {
                // moveToEagle
                moveRandom();
                //moveToEagle();
            }

            shootRandom();


            if (heading == north) {
                newY -= speed;
            } else if (heading == west) {
                newX -= speed;
            } else if (heading == south) {
                newY += speed;
            } else if (heading == east) {
                newX += speed;
            }

            // Может, в отдельную функцию?
            if (newX < 0) {
                newX = 0;
                heading = east;
            } else if (newX >= Game.WIDTH - SPRITE_SCALE * scale) {
                newX = Game.WIDTH - SPRITE_SCALE * scale;
                heading = west;
            }

            if (newY < 0) {
                newY = 0;
                heading = south;
            } else if (newY >= Game.HEIGHT - SPRITE_SCALE * scale) {
                newY = Game.HEIGHT - SPRITE_SCALE * scale;
                heading = north;
            }

            x = newX;
            y = newY;
        }

        elapsedTime++;
        fromChangeDirTime++;
        fromShootTime++;
    }

    private void moveRandom()
    {
        if (fromChangeDirTime > changeDirTime * 60)
        {
            fromChangeDirTime = 0;
            changeDirTime = ThreadLocalRandom.current().nextInt(2, 5 + 1);

            int direction = ThreadLocalRandom.current().nextInt(0, 3 + 1);
            if (direction == heading.toInt())
            {
                direction++;
                direction %= 4;
            }
            setDir(direction);
        }
    }

    private void shootRandom()
    {
        if(fromShootTime > shootTime * 60)
        {
            shoot();
            fromShootTime = 0;
        }
        shootTime = ThreadLocalRandom.current().nextInt(2, 4 + 1);
    }

    float oldDifX = 0;
    float oldDifY = 0;
    private boolean startedTracking = false;

//    private void moveToPlayer()
//    {
//        float difX = x - Player.getPX();
//        float difY = y - Player.getPY();
//
//        if(difX * oldDifX < 0)
//        {
//            if (difY < 0)
//                heading = south;
//            else
//                heading = north;
//        }
//        else
//        if(difY * oldDifY < 0)
//        {
//            if (difX < 0)
//                heading = east;
//            else
//                heading = west;
//        }
//
//        if(!startedTracking) {
//            if (Math.abs(difX) < Math.abs(y - difY)) {
//                if (difX < 0)
//                    heading = east;
//                else
//                    heading = west;
//            } else {
//                if (difY < 0)
//                    heading = south;
//                else
//                    heading = north;
//            }
//            startedTracking = true;
//        }
//
//        oldDifX = difX;
//        oldDifY = difY;
//    }

    private void moveToEagle()
    {

    }

    public void setDir(int direction)
    {
        switch (direction%4)
        {
            case 0:
                heading = north;
                break;
            case 1:
                heading = west;
                break;
            case 2:
                heading = south;
                break;
            case 3:
                heading = east;
                break;
        }
    }

    public void setLevel(int level)
    {
        super.setLevel(level);
        speed -= 0.5f;

        switch (level%8)
        {
            case 0:
            case 3:
            case 7:
                speed = 1f;
                break;
            case 1:
            case 2:
            case 4:
            case 6:
                speed = 1.5f;
                break;
            case 5:
                speed = 2.5f;
                break;
        }
    }





    @Override
    public void render(Graphics2D g) {
        spriteMap.get(heading).render(g, x, y, true);
    }
}
