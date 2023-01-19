#include <SFML/Graphics.hpp>
#include "windows.h" 
using namespace sf;


class Sprites {

public:
    Sprite background, name_game, start, exit, stick, background_game, ball, brick, block[18];

};

class Bool_class {
public:
    bool menu = true, game = false, moveball = true;
};

int main()
{
    RenderWindow window(VideoMode(1200, 800), "Arkanoid");
    Sprites spr;
    Bool_class bl;

    Texture t1, t2, t3, t4, t5, t6, t7,t8;
    t1.loadFromFile("pic/background2.jpg");
    t4.loadFromFile("pic/arka.png");

    t6.loadFromFile("pic/2.jpg");
    t5.loadFromFile("pic/stick.png");

    t7.loadFromFile("pic/ball.png");
    t8.loadFromFile("pic/brick.png");



    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++) {
            spr.block[j * 6 + i].setTexture(t8);
            spr.block[j * 6 + i].setTextureRect(IntRect(0, 0, 100, 50));
        }


    //spr.ball.setTexture(t7);
    //spr.brick.setTexture(t8);
    //spr.ball.setTexture(t7);
    //spr.stick.setTexture(t5);
    //spr.ball.setTexture(t7);
    //spr.brick.setTexture(t8);
    //spr.background_game.setTexture(t6);
    spr.background.setTexture(t1);
    spr.name_game.setTexture(t4);
    spr.name_game.setPosition(70, 120);
    spr.background.setPosition(0, 0);
    int coord_px_stick = 120;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
                if (event.key.code == Mouse::Left) {
                    Vector2i pos = Mouse::getPosition(window);

                    if (bl.menu) {
                        if (pos.x >= 85 && pos.x <= 200 && pos.y >= 540 && pos.y <= 620)
                            window.close();


                        if (pos.x >= 85 && pos.x <= 360 && pos.y >= 440 && pos.y <= 576) {
                            bl.menu = false;
                            bl.game = true;
                        }
                           
                    }
                }


        }



        

        window.clear();
        window.draw(spr.background);
        if (bl.menu == true) {
            // window.draw(spr.start);
            window.draw(spr.background);
            window.draw(spr.name_game);

            window.draw(spr.background_game);



            // window.draw(spr.exit);

        }
        if (bl.game == true) {


     


            spr.background_game.setTexture(t6);
            spr.background_game.setPosition(0, 0);
            window.draw(spr.background_game);

            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 3; j++)
                    spr.block[j * 6 + i].setPosition(25 + 200 * i, 10 + 100 * (j + 1));
            spr.ball.setTexture(t7);
            spr.stick.setTexture(t5);
            window.draw(spr.stick);
            window.draw(spr.ball);

            spr.stick.setPosition(465, 680);
            spr.ball.setPosition(510, 660);


            for (int i = 0; i < 18; i++) {
                window.draw(spr.block[i]);
            }


        }
        window.display();

    }

    return 0;
}