package by.bsu.zmiecer.game.entity;

import by.bsu.zmiecer.IO.Input;
import by.bsu.zmiecer.game.Game;
import by.bsu.zmiecer.graphics.Sprite;
import by.bsu.zmiecer.graphics.SpriteSheet;
import by.bsu.zmiecer.graphics.TextureAtlas;

import java.awt.event.KeyEvent;
import java.util.HashMap;

/**
 * Created by Zmiecer on 11.05.2016.
 */
public class Eagle extends Entity {

    protected Heading noHeading;
    protected String NO_HEADING = "NO_HEADING";
    private long respawnTime = 0;
    private double acceleration = 0;
    private int numberOfRespawns = 0;


    public Eagle(float x, float y, TextureAtlas atlas) {
        super(EntityType.Eagle, x, y, 2, atlas);

        spriteMap = new HashMap<>();

        spritesPerHeading = 2;
        noHeading = new Heading(19,  2,  spritesPerHeading,  1,  NO_HEADING);
        heading = noHeading;
        createSpritesForHeading();
    }

    @Override
    public void update(Input input) {
        if (input.getKey(KeyEvent.VK_ENTER)) {
            if (elapsedTime > 1.5 * 60) {
                Game.respawn();
                elapsedTime = 0;
            }
        }
        if (input.getKey(KeyEvent.VK_R)) {
            if (elapsedTime > 1.5 * 60) {
                Game.restart();
                elapsedTime = 0;
                respawnTime = 0;
                acceleration = 0;
            }
        }

        double res;
        if(numberOfRespawns < 20) {
            res = 5 * 60 + Math.exp(-acceleration / 1000) * 1000;
        }
        else
            res = 5*60;


        if(respawnTime > res) {
            Game.respawn();
            respawnTime = 0;
            numberOfRespawns++;
        }
        elapsedTime++;
        respawnTime++;
        acceleration++;
    }

    protected void create(Heading heading)
    {
        SpriteSheet sheet = new SpriteSheet(heading.texture(atlas), spritesPerHeading, SPRITE_SCALE);
        Sprite sprite = new Sprite(sheet, scale);
        spriteMap.put(heading, sprite);
    }

    @Override
    protected void createSpritesForHeading() {
        create(noHeading);
    }

}
