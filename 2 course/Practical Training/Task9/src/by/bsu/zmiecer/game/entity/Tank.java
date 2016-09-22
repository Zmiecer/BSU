package by.bsu.zmiecer.game.entity;

import by.bsu.zmiecer.game.Game;
import by.bsu.zmiecer.graphics.Sprite;
import by.bsu.zmiecer.graphics.SpriteSheet;
import by.bsu.zmiecer.graphics.TextureAtlas;

/**
 * Created by Zmiecer on 10.05.2016.
 */
public abstract class Tank extends Entity {

    protected int bulletSpeed = 3;

    public Tank(EntityType type, float x, float y, int level, TextureAtlas atlas) {
        super(type, x, y, level, atlas);
        spritesPerHeading = 2;
    }

    protected void shoot()
    {
        float shootX = x + 4*scale;
        float shootY = y + 4*scale;
        if (heading == north) {
            shootY -= 12 * scale;
            shootX -= 2;
        }
        else if (heading == west) {
            shootX -= 12 * scale;
        }
        else if (heading == south) {
            shootY += 12 * scale;
            shootX -= 2;
        }
        else if (heading == east) {
            shootX += 12 * scale;
        }
        Game.addEntity(new Bullet(shootX/Entity.SPRITE_SCALE, shootY/Entity.SPRITE_SCALE, bulletSpeed, heading.toString(), atlas));
    }

    protected void setLevel(int level)
    {
        this.level = level;

        createSpritesForHeading();

        switch (level%8)
        {
            case 0:
                speed = 1.5f;
                bulletSpeed = 3;
                break;
            case 1:
                bulletSpeed = 3;
                speed = 2f;
                break;
            case 2:
                bulletSpeed = 4;
                speed = 2f;
                break;
            case 3:
                speed = 1.5f;
                bulletSpeed = 5;
                break;
            case 4:
                speed = 2f;
                bulletSpeed = 4;
                break;
            case 5:
                speed = 2.5f;
                bulletSpeed = 3;
                break;
            case 6:
                speed = 2f;
                bulletSpeed = 5;
                break;
            case 7:
                speed = 1.5f;
                bulletSpeed = 5;
                break;
        }
    }

    @Override
    public void destroy()
    {

        Game.addEntity(new Explosion(x/Entity.SPRITE_SCALE, y/Entity.SPRITE_SCALE, atlas));
        Game.destroy(this);
    }

    protected void create(Heading heading, int level)
    {
        heading.setY(level);
        SpriteSheet sheet = new SpriteSheet(heading.texture(atlas), spritesPerHeading, SPRITE_SCALE);
        Sprite sprite = new Sprite(sheet, scale);
        spriteMap.put(heading, sprite);
    }

    protected void createSpritesForHeading()
    {
        create(north, level);
        create(west, level);
        create(south, level);
        create(east, level);
    }

    public void shot()
    {
        switch (level%8)
        {
            case 0:
            case 5: {
                if (this.type == EntityType.ENEMY) {
                    Game.enemyCount--;
                    //System.out.println(Game.enemyCount);
                }
                else
                {
                    Game.addEntity(new GameOverTile(0, atlas));
                    Game.addEntity(new GameOverTile(1, atlas));
                }
                destroy();
                break;
            }
            case 1:
            case 2:
            case 4:
            case 6:
                setLevel(0);
                break;
            case 3:
                setLevel(2);
                break;
            case 7:
                setLevel(6);
                break;
        }
    }

}
