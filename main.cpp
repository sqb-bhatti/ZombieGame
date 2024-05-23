


#include <iostream>
#include "Player.h"
#include "CreateBackground.h"

using namespace  sf;


enum class State { PAUSED,
    LEVELING_UP,
    GAME_OVER,
    PLAYING };



int main() {
    // Start with the GAME_OVER state
    State state = State::GAME_OVER;

    // Get the screen resolution and create an SFML window
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

//    RenderWindow window(VideoMode(resolution.x, resolution.y), "Zombie Game", Style::Fullscreen);

    // Create a video mode object
    VideoMode vm(1920, 1080);

    // Create and open a window for the game
    RenderWindow window(vm, "Zombie Game");

    // Create a an SFML View for the main action
    View mainView(FloatRect(0, 0, resolution.x, resolution.y));


    Clock clock;

    // How long has the PLAYING state been active
    Time gameTimeTotal;

    // Where is the mouse in relation to world coordinates
    Vector2f mouseWorldPosition;

    // Where is the mouse in relation to screen coordinates
    Vector2i mouseScreenPosition;

    // Create an instance of the Player class
    Player player;

    // The boundaries of the arena
    IntRect arena;

    // Create the background
    VertexArray background;

    // Load the texture for our background vertex array
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background_sheet.png");

    // The main game loop
    while (window.isOpen()) {
        /*
         ****************************************
         Handle the players input
         ****************************************
         */
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyPressed) {
                // Pause a game while playing
                if (event.key.code == Keyboard::Return && state == State::PLAYING) {
                    state = State::PAUSED;
                }

                // Restart while paused
                else if (event.key.code == Keyboard::Return && state == State::PAUSED) {
                    state = State::PLAYING;
                    // Reset the clock so there isn't a frame jump

                    /*
                     The reason we restart clock after switching from PAUSED to PLAYING is because, while the game is
                     paused, the elapsed time still accumulates. If we didn't restart the clock, all our objects would
                     update their locations as if the frame had just taken a very long time.
                     */
                    clock.restart();
                }

                // Start a new game while in GAME_OVER state. GAME_OVER state is the state where the home screen is
                // displayed.
                else if (event.key.code == Keyboard::Return && state == State::GAME_OVER) {
                    state = State::LEVELING_UP;
                }

                if (state == State::PLAYING) {

                }
            }
        }  // End event polling

        // Handle the player quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        // Handle W,A,S,D keys while playing
        if (state == State::PLAYING) {
            if (Keyboard::isKeyPressed(Keyboard::W)) {
                player.moveUp();
            } else {
                player.stopUp();
            }

            if (Keyboard::isKeyPressed(Keyboard::S)) {
                player.moveDown();
            } else {
                player.stopDown();
            }

            if (Keyboard::isKeyPressed(Keyboard::A)) {
                player.moveLeft();
            } else {
                player.stopLeft();
            }

            if (Keyboard::isKeyPressed(Keyboard::D)) {
                player.moveRight();
            } else {
                player.stopRight();
            }
        }  // End W,A,S,D while playing


        // Handle the LEVELING up state
        if (state == State::LEVELING_UP) {
            // Handle the player LEVELING up.
            // handle the keyboard keys 1, 2, 3, 4, 5, and 6.
            if (event.key.code == Keyboard::Num1) {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num2) {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num3) {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num4) {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num5) {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num6) {
                state = State::PLAYING;
            }

            if (state == State::PLAYING) {
                // Prepare the level
                arena.width = 500;
                arena.height = 500;
                arena.left = 0;
                arena.top = 0;

                // Pass the vertex array by reference to the createBackground function
                int tileSize = createBackground(background, arena);
//                int tileSize = 50;

                // Spawn the player in the middle of the arena
                player.spawn(arena, resolution, tileSize);

                // Reset the clock so there isn't a frame jump
                clock.restart();
            }
        } // End LEVELING up


        /*
        ****************************************
        Update THE FRAME
        ****************************************
        */

        if (state == State::PLAYING) {
            // Update the delta time
            Time dt = clock.restart();

            // Update the total game time
            gameTimeTotal += dt;

            // Make a decimal fraction of 1 from the delta time
            float dtAsSeconds = dt.asSeconds();

            // Where is the mouse pointer
            mouseScreenPosition = Mouse::getPosition();

            // Convert mouse position to world coordinates of mainView
            mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

            // Update the player
            player.update(dtAsSeconds, Mouse::getPosition());

            // Make a note of the players new position
            Vector2f playerPosition(player.getCenter());

            // Make the view centre around the player
            mainView.setCenter(player.getCenter());

        } // End updating the scene


        /*
        ****************************************
        Draw THE SCENE
        ****************************************
        */
        if (state == State::PLAYING) {
            window.clear();

            // set the mainView to be displayed in the window AND draw everything related to it
            window.setView(mainView);

            // Draw the background. To draw a vertex array with a texture, pass it directly to the draw function
            window.draw(background, &textureBackground);

            // Draw the player
            window.draw(player.getSprite());
        }

        if (state == State::LEVELING_UP) {

        }

        if (state == State::PAUSED) {

        }

        if (state == State::GAME_OVER) {

        }

        window.display();

    } // End game loop

    return 0;
}
