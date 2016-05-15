package by.bsu.zmiecer.game.entity;

import by.bsu.zmiecer.game.Game;
import by.bsu.zmiecer.graphics.TextureAtlas;

/**
 * Created by Zmiecer on 10.05.2016.
 */
public abstract class Tank extends Entity {
    public Tank(EntityType type, float x, float y, int level, TextureAtlas atlas) {
        super(type, x, y, level, atlas);
    }

    protected void shoot()
    {
        float shootX = x + 4*scale;
        float shootY = y + 4*scale;
        if (heading == north) {
            shootY -= 24;
        }
        else if (heading == west) {
            shootX -= 24;
        }
        else if (heading == south) {
            shootY += 24;
        }
        else if (heading == east) {
            shootX += 24;
        }
        Game.addEntity(new Bullet(shootX, shootY, bulletSpeed, heading.toString(), atlas));
    }

    protected void setLevel(int level)
    {
        this.level = level;

        createSpritesForHeading();
    }

}
