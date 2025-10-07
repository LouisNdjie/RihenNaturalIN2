#include "Count.h"

namespace nkentseu{

Count::Count(const ApplicationProperties& propertiy){}
Count::~Count(){}

void Count::Setup()
{
    position.x = GetWindowWidth()/2;
    position.y = 100.0f;
    Background(graphics::Color::Black);
}
void Count::Update(float deltaTime)
{
    Background(graphics::Color::Black);
    position.y += gravity*deltaTime;
    if (position.y >= GetWindowHeight()-r)
    {
        position.y -= friction*deltaTime;
    }
    
}
void Count::Draw()
{
    Fill(graphics::Color::Yellow);
    Circle(position, r);
}
}

//force(loi de newton), ressort, physique, champ magnetique