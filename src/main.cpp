#include "engine/io/Window.h"
#include "engine/utils/Timer.h"
#include "engine/graphics/Sprite.h"

int main() {

    Window window("Weird Chess", false, false);
    spriteUpdateTileSize();
    Shader shader("main");
    auto wonImg = createCharImage("won.png", true);
    unsigned int wonTexture = createTexture(wonImg);
    Sprite sprite(wonTexture);


    glfwSetKeyCallback(window.getWindow(), [](auto window, auto key, auto scancode, auto action, auto mods) {
        std::cout << "Key: " << key << std::endl;
    });

    static float mX, mY;
    glfwSetMouseButtonCallback(window.getWindow(), [](auto window, auto button, auto action, auto mods) {
        std::cout << "X: " << mX << "Y: " << mY << std::endl;
    });
    glfwSetCursorPosCallback(window.getWindow(), [](auto window, auto xpos, auto ypos) {
        mX = xpos;
        mY = ypos;
    });


    // Run the game
    Timer::nowDelta();
    bool running = true;
    while(running)
    {
        if (glfwWindowShouldClose(window.getWindow())) {
            running = false;
            break;
        }
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        double delta = Timer::nowDelta();
        sprite.render(Window::WIDTH / 2.0f, Window::HEIGHT / 2.0f, shader, false);

        // Render end
        glfwSwapBuffers(window.getWindow());
    }
    shader.destroy();

    return 0;
}
