#pragma once
#include "Core/Application.h"
#include "Core/Math/Random.h"
#include "Core/Math/Vector2.h"

namespace nkentseu {
    class DemoRandomWalk : public Application {
        private:
            struct histogramme
            {
                std::vector<math::Vector2> hist;
                std::string frequency;
            };
            std::vector<histogramme> gaussian;
            math::Vector2 position;

        public:
            DemoRandomWalk(const ApplicationProperties& props);

        protected:
            void Setup() override;
            void Update(float deltaTime) override;
            void Draw() override;
        
        private:
            void HeightAleatoryDirection();
            void ToMousePosition();
            void GaussianHistogramme();
    };
}
