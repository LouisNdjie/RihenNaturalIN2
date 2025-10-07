#include "DemoRandomWalk.h"

namespace nkentseu {
    DemoRandomWalk::DemoRandomWalk(const ApplicationProperties& props) : Application(props) {}

    void DemoRandomWalk::Setup() {
        position = math::Vector2(GetWindowWidth() / 2.0f, GetWindowHeight() / 2.0f);
        Background(graphics::Color::Black);
    }

    void DemoRandomWalk::Update(float deltaTime) {
        // La logique de mise à jour sera dans Draw pour cet exemple simple
    }

    void DemoRandomWalk::Draw() {
        // Dessiner le marcheur
        Fill(graphics::Color::Blue);
        NoStroke();
        Circle(position, 4.0f);

        this->HeightAleatoryDirection();
        // Garder dans les limites de l'écran
        position.x = std::max(0.0f, std::min(position.x,(float)GetWindowWidth()));
        position.y = std::max(0.0f, std::min(position.y,(float)GetWindowHeight()));
    }
    void DemoRandomWalk::HeightAleatoryDirection()
    {
        // Prendre un pas aléatoire
        int choice = math::Random::Range(0, 7);

        if (choice == 0) {
            position.x++;
        } else if (choice == 1) {
            position.x--;
        } else if (choice == 2) {
            position.y++;
        } else if (choice == 3) {
            position.y--;
        } else if (choice == 4) {
            position.x++;
            position.y++;
        } else if (choice == 5) {
            position.x++;
            position.y--;
        } else if (choice == 6) {
            position.x--;
            position.y++;
        } else {
            position.x--;
            position.y--;
        }

    }
    void DemoRandomWalk::ToMousePosition()
    {
        float r = math::Random::Value();

        if (r >= 0.5f) {
            float mousex = 0, mousey = 0;
            SDL_GetMouseState(&mousex, &mousey);
            if (position.x < mousex) {
                position.x++;
            }else if (position.x > mousex) {
                position.x--;
            }else if (position.y < mousey) {
                position.y++;
            }else if (position.y > mousey) {
                position.y--;
            }
        }else {
               this->HeightAleatoryDirection();
        }
    }
    void DemoRandomWalk::GaussianHistogramme()
    {
        // Mouvement avec distribution gaussienne
        float stepX = math::Random::Gaussian(0.0f, 2.0f);
        float stepY = math::Random::Gaussian(0.0f, 2.0f);

        position.x += stepX;
        position.y += stepY;

        gaussian.emplace_back().hist.emplace_back(position);
        gaussian.front().hist.emplace_back(position);

        histogramme& histo = gaussian.front();

        std::vector<math::Vector2> histo_position;
        std::vector<int> value;
        for (const auto& pos : histo.hist)
        {
            bool present = false;
            for (int i = 0; i < histo_position.size(); ++i)
            {
                if (position.x == histo_position[i].x && position.y == histo_position[i].y) {
                    value[i]++;
                    present = true;
                    break;
                }
                
            }
            if (!present) {
                histo_position.emplace_back(position);
                value.push_back(1);
            }
        }

        histo.frequency.clear();
        for (int f : value) {
            histo.frequency += std::string(f, '#');
        }
        
        for (int i = 0; i < histo_position.size(); i++)
        {
            std::cout << " Position (" << histo_position[i].x <<", " <<histo_position[i].y <<") :";
            std::cout << std::string(value[i], '#') << " (" << value[i] << ")" <<std::endl; 
        }
 
    }
}
// Fonction de création
nkentseu::Application* CreateRandomWalkDemo(const nkentseu::ApplicationProperties& props) {
    return new nkentseu::DemoRandomWalk(props);
}
