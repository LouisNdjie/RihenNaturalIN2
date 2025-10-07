#pragma once
#include "Core/Application.h"
#include "Core/Math/Vector2.h"
#include "Core/Math/Matrix3x3.h"

namespace nkentseu{
    class Count :  public Application {
        private:
            math::Vector2 position;
            float gravity = 9.81f*20;
            float r = 100.0f;
            float friction = 20.0f*50;
        public:
            Count(const ApplicationProperties& propertiy);
            ~Count();
        protected:
            void Setup() override;
            void Update(float deltaTime) override;
            void Draw() override;
    };
}

