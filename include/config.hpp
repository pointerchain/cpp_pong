// include/config.hpp

#pragma once

namespace Config {

namespace Window {

constexpr unsigned int kWidth{2500};
constexpr unsigned int kHeight{1400};

}  // namespace Window

namespace Paddle {

constexpr float kSpeed{1000.f};
constexpr float kWidth{25.f};
constexpr float kHeight{200.f};
constexpr float kXOffset{150.f};

}  // namespace Paddle

namespace Ball {

constexpr float kSpawnTimer{1.f};
constexpr float kInitialSpeed{1250.f};
constexpr float kAccelerationSpeed{15.f};
constexpr float kRadius{25.f};

}  // namespace Ball

}  // namespace Config