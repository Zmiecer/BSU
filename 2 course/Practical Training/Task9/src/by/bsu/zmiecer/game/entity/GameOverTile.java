package by.bsu.zmiecer.game.entity;

import by.bsu.zmiecer.IO.Input;
import by.bsu.zmiecer.game.Game;
import by.bsu.zmiecer.game.entity.Entity;
import by.bsu.zmiecer.game.entity.EntityType;
import by.bsu.zmiecer.graphics.Sprite;
import by.bsu.zmiecer.graphics.SpriteSheet;
import by.bsu.zmiecer.graphics.TextureAtlas;

import java.util.HashMap;

/**
 * Created by Zmiecer on 12.05.2016.
 */
public class GameOverTile extends Entity {

    protected Heading noHeading;
    protected String NO_HEADING = "NO_HEADING";

    public GameOverTile(int kek, TextureAtlas atlas) {
        super(EntityType.GameOverTile, (9 + kek) * Game.SCALE, 7 * Game.SCALE, 0, atlas);
        spritesPerHeading = 1;
        noHeading = new Heading(18 + kek,  11.5f,  1,  1,  NO_HEADING);

        spriteMap = new HashMap<>();
        heading = noHeading;
        SpriteSheet sheet = new SpriteSheet(noHeading.texture(atlas), spritesPerHeading, SPRITE_SCALE);
        Sprite sprite = new Sprite(sheet, scale);
        spriteMap.put(noHeading, sprite);
    }

    @Override
    public void update(Input input) {

    }
}
