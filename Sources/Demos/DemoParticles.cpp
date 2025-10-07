#include "DemoParticles.h"
#include "Core/Log.h"

#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>

namespace nkentseu {


    DemoParticles::DemoParticles(const ApplicationProperties& props){}

    void DemoParticles::Setup() {
        walker.push_back(math::Vector2(10, 10));   
    }

    void DemoParticles::Update(float deltaTime) {
        walker[0] = math::Vector2(math::Random::Range<int>(-1, 10),math::Random::Range<int>(-1, 10));
    }

    void DemoParticles::Draw() {
        Background(graphics::Color::White, true);
        math::Vector2 square(0, 0);
        Fill(graphics::Color::White);
        Stroke(graphics::Color::Black);
        for (int i = 0; i < (GetWindowWidth()/10); i++)
        {
            for (int j = 0; j < (GetWindowHeight()/10); j++)
            {
                square.x = (i*10);
                square.y = (j*10);
                Rect(square, 10); 
            }
            
        }    
        Fill(graphics::Color::Red);
        for (auto walk:walker)
        {
            Rect(math::Vector2(walk.x*10, walk.y*10), math::Vector2(10, 10));
        }
    }

} // namespace nkentseu