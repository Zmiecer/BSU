package by.bsu.zmiecer.game.entity;

import by.bsu.zmiecer.IO.Input;
import by.bsu.zmiecer.graphics.Sprite;
import by.bsu.zmiecer.graphics.SpriteSheet;
import by.bsu.zmiecer.graphics.TextureAtlas;

import java.awt.*;
import java.util.HashMap;

/**
 * Created by Zmiecer on 11.05.2016.
 */
public class Explosion extends Entity {

    Heading noHeading;
    String NO_HEADING = "NO_HEADING";

    public Explosion(float x, float y, TextureAtlas atlas) {
        super(EntityType.Explosion, x, y, 6, atlas);

        spriteMap = new HashMap<>();

        noHeading = new Heading(16,  8,  3,  1,  NO_HEADING);
        heading = noHeading;
        SPRITES_PER_HEADING = 3;
        createSpritesForHeading();


    }

    @Override
    public void update(Input input) {

    }

    protected void create(Heading heading)
    {
        SpriteSheet sheet = new SpriteSheet(heading.texture(atlas), SPRITES_PER_HEADING, SPRITE_SCALE);
        Sprite sprite = new Sprite(sheet, scale);
        spriteMap.put(heading, sprite);
    }

    @Override
    protected void createSpritesForHeading() {
        create(noHeading);
    }

    @Override
    public void render(Graphics2D g) {
        spriteMap.get(heading).render(g, x, y, true);
    }
}
