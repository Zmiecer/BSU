package by.bsu.zmiecer.game.entity;

import by.bsu.zmiecer.IO.Input;
import by.bsu.zmiecer.game.Game;
import by.bsu.zmiecer.graphics.Sprite;
import by.bsu.zmiecer.graphics.SpriteSheet;
import by.bsu.zmiecer.graphics.TextureAtlas;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.util.Map;

/**
 * Created by Zmiecer on 09.05.2016.
 */
public abstract class Entity
{
    public final EntityType type;

    protected float x;
    protected float y;

    public static final int         SPRITE_SCALE        = 16;
    protected int                   spritesPerHeading = 1;

    public void shot()
    {
        Game.destroy(this);
    };

    public class Heading
    {
        private int x, y, w, h;
        private String name;

        Heading(float x, float y, float w, float h, String name)
        {
            this.x = (int)(x * SPRITE_SCALE);
            this.y = (int)(y * SPRITE_SCALE);
            this.w = (int)(w * SPRITE_SCALE);
            this.h = (int)(h * SPRITE_SCALE);
            this.name = name;
        }

        public BufferedImage texture(TextureAtlas atlas)
        {
            return atlas.cut(x, y, w, h);
        }

        public void setX(float x) {
            this.x = (int)(x * SPRITE_SCALE);
        }

        public void setY(float y) {
            this.y = (int)(y * SPRITE_SCALE);
        }

        public void setW(float w) {
            this.w = (int)(w * SPRITE_SCALE);
        }

        public void setH(float h) {
            this.h = (int)(h * SPRITE_SCALE);
        }

        @Override
        public String toString() {
            return name;
        }

        public int toInt()
        {
            switch (heading.toString())
            {
                case NORTH:
                    return 0;
                case WEST:
                    return 1;
                case SOUTH:
                    return 2;
                case EAST:
                    return 3;
            }
            return 0;
        }

        public void setName(String name) {
            this.name = name;
        }
    }


    protected Heading                 heading;
    protected Map<Heading, Sprite>    spriteMap;
    protected float                   scale;
    protected float                   speed;
    TextureAtlas                      atlas;
    Heading                           north, south, east, west;
    protected static final String     NORTH     = "NORTH";
    protected static final String     WEST      = "WEST";
    protected static final String     SOUTH     = "SOUTH";
    protected static final String     EAST      = "EAST";
    protected int                     level     = 0;
    protected int                     elapsedTime;



    protected Entity(EntityType type, float x, float y, int level, TextureAtlas atlas)
    {
        this.type = type;
        this.x = x*SPRITE_SCALE;
        this.y = y*SPRITE_SCALE;
        this.scale = Game.SCALE;
        this.level = level;
        this.atlas = atlas;
    }

    public abstract void update(Input input);

    public void render(Graphics2D g)
    {
        spriteMap.get(heading).render(g, x, y, false);
    }

    public float getX() {
        return x;
    }

    public float getY() {
        return y;
    }

    protected void createSpritesForHeading()
    {
        create(north);
        create(west);
        create(south);
        create(east);
    }

    protected void create(Heading heading)
    {
        SpriteSheet sheet = new SpriteSheet(heading.texture(atlas), spritesPerHeading, SPRITE_SCALE);
        Sprite sprite = new Sprite(sheet, scale);
        spriteMap.put(heading, sprite);
    }

    public Heading getHeading() {
        return heading;
    }

    public void setDir(int direction){}

    public void destroy()
    {
        Game.destroy(this);
    }
}
