#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>
using namespace sf;

sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
GameManager gm;


void testFunc(Gui *g)
{
    BasicButton* cb = static_cast<BasicButton*>(g);
    if (cb->clicked)
    {
        std::cout << "Click" << std::endl;
        gm.guiManager.mainForm.getForm("login_form")->setVisible(0);
        dynamic_cast<DisplayedText*>(gm.guiManager.mainForm.getForm("main_form")->getGui("welcome_text"))->setText("Hello mr. " + dynamic_cast<TextInput*>(gm.guiManager.mainForm.getForm("login_form")->getGui("login_textbox"))->getString() + "!");
        gm.guiManager.mainForm.getForm("main_form")->setVisible(1);
    }
}
void testFunc1(Gui* g)
{
    BasicButton* bb = static_cast<BasicButton*>(g);
    if (bb->covered)
    {
        bb->setFillColor(sf::Color::Red);
        std::cout << "Cover" << std::endl;
    }
    else
    {
        bb->setFillColor(sf::Color::White);
        std::cout << "Uncover" << std::endl;
    }
}


void cowerKeybord(Gui* g)
{
    BasicTextInput* bb = static_cast<BasicTextInput*>(g);
    if (bb->covered)
    {
        bb->setOutlineColor(sf::Color::Red);
        std::cout << "Cover" << std::endl;
    }
    else
    {
        bb->setOutlineColor(sf::Color::Black);
        std::cout << "Uncover" << std::endl;
    }
}
void updateSlider(Gui* g)
{
    Slider* bb = static_cast<Slider*>(g);
    if (bb->updated)
    {
        Slider* slider = static_cast<Slider*>(g);
        std::cout << slider->getValue() << "- value" << std::endl;
        std::cout << slider->getState() << "- state" << std::endl;
        bb->updated = 0;
    }
}

void noneFunc(Gui* g)
{

}

int main()
{
    sf::Font f;
    f.loadFromFile("Samson.ttf");

    gm.guiManager.mainForm.createForm("login_form", FloatRect((1920 - 1000) / 2, (1080 - 600) / 2, 1000, 600), 1);
    gm.guiManager.mainForm.getForm("login_form")->createDisplayText("welcome_text", FloatRect((1920 - 1000) / 2+200, (1080 - 600) / 2+100,0,0), "Pleace enter your login!",f,1);
    gm.guiManager.mainForm.getForm("login_form")->createButton("login_button", "Login", FloatRect((1920 - 1000) / 2 + 475, (1080 - 600) / 2 + 170, 60, 50), "login_func", "main_cowerbutton", f, 1);
    gm.guiManager.mainForm.getForm("login_form")->createTextInput("login_textbox", "Login", FloatRect((1920 - 1000) / 2 + 200, (1080 - 600) / 2 + 170, 265, 50), "cowerKeybord", f, 1);

    gm.guiManager.mainForm.createForm("main_form", FloatRect((1920 - 1000) / 2, (1080 - 600) / 2, 1000, 600), 1);
    gm.guiManager.mainForm.getForm("main_form")->createDisplayText("welcome_text", FloatRect((1920 - 1000) / 2 + 200, (1080 - 600) / 2 + 100, 0, 0), "", f, 1);
    //std::string s = gm.guiManager.mainForm.getForm("login_form")->getGui("login_button")->to_json();
    //std::cout << s;
    //gm.guiManager.mainForm.createGuiByJson("test", s, f);
    //gm.guiManager.mainForm.getGui("test")->setPosition(0,0);
    /*
    gm.guiManager.createButton("tesr","Loool",FloatRect(100,200,60,50), "test", "test1", f, 1);
    gm.guiManager.createButton("tesr2", "Loool", FloatRect(210, 200, 60, 50), "test", "test1", f, 1);
    gm.guiManager.createButton("tesr3", "Loool", FloatRect(320, 200, 60, 50), "test", "test1", f, 1);
    gm.guiManager.createButton("tesr4", "Loool", FloatRect(430, 200, 60, 50), "test", "test1", f, 1);
    gm.guiManager.createButton("tesr5", "Loool", FloatRect(540, 200, 60, 50), "test", "test1", f, 1);
    gm.guiManager.createTextInput("testTextInput1", "Tip", FloatRect(540, 250, 300, 100), "cowerKeybord", f, 1);
    gm.guiManager.createSlider("slider", 50, 150, 100, FloatRect(1000, 200, 150, 36), "slider", 1);
    */
    gm.guiManager.commands["login_func"] = testFunc;
    gm.guiManager.commands["main_cowerbutton"] = testFunc1;
    gm.guiManager.commands["cowerKeybord"] = cowerKeybord;
    gm.guiManager.commands["slider"] = updateSlider;
    gm.guiManager.commands["none"] = noneFunc;
    //gm.guiManager.commands["test1"] = testFunc1;
    

    Clock clock;
    while (window.isOpen())
    {
        float gameTime = clock.getElapsedTime().asMicroseconds();
        gameTime /= 400;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            gm.guiManager.inputEvent(event);
        }
        Vector2i mouseV = sf::Mouse::getPosition(window);
        gm.guiManager.update(gameTime, mouseV);

        window.clear(sf::Color::Blue);
        gm.guiManager.draw(window);
        window.display();
    }

    return 0;
}