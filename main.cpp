#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    int numCols = 25; // You would read these from the config file, but it's hard-coded here
    int numRows = 16;

    // create the window
    sf::RenderWindow window(sf::VideoMode((numCols * 32), (numRows * 32) + 100), "My window");

    sf::Texture hiddenTileTexture;
    hiddenTileTexture.loadFromFile("images/tile_hidden.png"); // you might have this in files/images/<file>

    sf::Sprite hiddenTile;
    hiddenTile.setTexture(hiddenTileTexture);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        for(int i = 0; i < numCols; i++) {
            for(int j = 0; j < numRows; j++) {
                hiddenTile.setPosition(i * 32, j * 32);
                window.draw(hiddenTile);
            }
        }

        // TODO: Working with digits.png
        int digitsNum;
        cin >> digitsNum;

        int onesPlace = digitsNum % 10;
        if(onesPlace < 0) {onesPlace *= -1;}
        int tensPlace = (digitsNum / 10) % 10;
        if(tensPlace < 0) {tensPlace *= -1;}
        int hundredsPlace = digitsNum / 100;
        if(hundredsPlace < 0) {hundredsPlace *= -1;}

        if(digitsNum < 0) {
            sf::Texture negativeDigitTexture;
            negativeDigitTexture.loadFromFile("images/digits.png", sf::IntRect(210, 0, 21, 32));
            sf::Sprite negativeDigit;
            negativeDigit.setTexture(negativeDigitTexture);
            negativeDigit.setPosition(21, (numRows * 32) + 16);
            window.draw(negativeDigit);
        }

        sf::Texture hundredsDigitTexture;
        hundredsDigitTexture.loadFromFile("images/digits.png", sf::IntRect(hundredsPlace * 21, 0, 21, 32));
        sf::Sprite hundredsDigit;
        hundredsDigit.setTexture(hundredsDigitTexture);
        hundredsDigit.setPosition(42, (numRows * 32) + 16);
        window.draw(hundredsDigit);

        sf::Texture tensDigitTexture;
        tensDigitTexture.loadFromFile("images/digits.png", sf::IntRect(tensPlace * 21, 0, 21, 32));
        sf::Sprite tensDigit;
        tensDigit.setTexture(tensDigitTexture);
        tensDigit.setPosition(hundredsDigit.getPosition().x + 21, hundredsDigit.getPosition().y);
        window.draw(tensDigit);

        sf::Texture onesDigitTexture;
        onesDigitTexture.loadFromFile("images/digits.png", sf::IntRect(onesPlace * 21, 0, 21, 32));
        sf::Sprite onesDigit;
        onesDigit.setTexture(onesDigitTexture);
        onesDigit.setPosition(tensDigit.getPosition().x + 21, tensDigit.getPosition().y);
        window.draw(onesDigit);






        // end the current frame123

        window.display();
    }

    return 0;
}