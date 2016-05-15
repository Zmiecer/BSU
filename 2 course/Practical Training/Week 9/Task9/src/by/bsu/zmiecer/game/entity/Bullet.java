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

    public Bullet(float x, float y, int level, String flight, TextureAtlas atlas)
    {
        super(EntityType.Bullet, x, y, 0, atlas);
        SPRITES_PER_HEADING = 1;

        spriteMap = new HashMap<>();

        north = new Heading(20.0f,  6.25f,  0.5f,  0.5f,   NORTH);
        west = new Heading( 20.5f,  6.25f,  0.5f,  0.5f,   WEST);
        south = new Heading(21.0f,  6.25f,  0.5f,  0.5f,   SOUTH);
        east = new Heading( 21.5f,  6.25f,  0.5f,  0.5f,   EAST);



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

        setLevel(level);
    }

    @Override
    protected void create(Heading heading, int level) {
        SpriteSheet sheet = new SpriteSheet(heading.texture(atlas), SPRITES_PER_HEADING, SPRITE_SCALE/2);
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

    private void setLevel(int level)
    {
        if (level%2 == 0)
            speed = 4;
        else
            speed = 6;
    }

    private void destroy()
    {
        Game.destroy(this);
    }
}
