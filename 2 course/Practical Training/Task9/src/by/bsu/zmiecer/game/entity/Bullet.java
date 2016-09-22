package by.bsu.zmiecer.game.entity;

import by.bsu.zmiecer.IO.Input;
import by.bsu.zmiecer.game.Game;
import by.bsu.zmiecer.graphics.Sprite;
import by.bsu.zmiecer.graphics.SpriteSheet;
import by.bsu.zmiecer.graphics.TextureAtlas;

import java.util.HashMap;


/**
 * Created by Zmiecer on 09.05.2016.
 */
public class Bullet extends Entity {

    public Bullet(float x, float y, int speed, String flight, TextureAtlas atlas)
    {
        super(EntityType.BULLET, x, y, speed, atlas);
        this.speed = speed;

        spriteMap = new HashMap<>();

        north = new Heading(20.0f,  6.25f,  0.5f,  0.5f,   NORTH);
        west = new Heading( 20.5f,  6.25f,  0.5f,  0.5f,   WEST);
        south = new Heading(21.0f,  6.25f,  0.5f,  0.5f,   SOUTH);
        east = new Heading( 21.5f,  6.25f,  0.5f,  0.5f,   EAST);
        spritesPerHeading = 1;



        createSpritesForHeading();

        switch (flight)
        {
            case NORTH:
                heading = north;
                break;
            case WEST:
                heading = west;
                break;
            case SOUTH:
                heading = south;
                break;
            case EAST:
                heading = east;
                break;
        }

    }

    @Override
    protected void create(Heading heading) {
        SpriteSheet sheet = new SpriteSheet(heading.texture(atlas), spritesPerHeading, SPRITE_SCALE/2);
        Sprite sprite = new Sprite(sheet, scale);
        spriteMap.put(heading, sprite);
    }

    @Override
    public void update(Input input)
    {
        float newX = x;
        float newY = y;

        if(heading == north)
        {
            newY -= speed;
        }
        else if(heading == west)
        {
            newX -= speed;
        }
        else if(heading == south)
        {
            newY += speed;
        }
        else if (heading == east)
        {
            newX += speed;
        }

        if(x < 0 || x >= Game.WIDTH - SPRITE_SCALE*scale/2 || y < 0 || y >= Game.HEIGHT - SPRITE_SCALE*scale/2)
            destroy();

        x = newX;
        y = newY;
    }
}
