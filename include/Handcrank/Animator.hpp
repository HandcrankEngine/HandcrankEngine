#include "Animation.hpp"
#include "Handcrank.hpp"

namespace Handcrank
{

class Animator : public RenderObject
{
  public:
    enum class Mode : uint8_t
    {
        PARALLEL,
        SEQUENCE
    };

  private:
    Mode mode = Mode::SEQUENCE;

    bool looping = false;

    std::vector<std::shared_ptr<Animation>> animations;

    size_t currentAnimationIndex = 0;

  public:
    explicit Animator() = default;
    explicit Animator(Mode mode) { this->mode = mode; }
    explicit Animator(Mode mode, bool looping)
    {
        this->mode = mode;
        this->looping = looping;
    }

    ~Animator() { animations.clear(); }

    void Start() override
    {
        if (animations.empty())
        {
            return;
        }

        if (mode == Mode::PARALLEL)
        {
            for (auto &animation : animations)
            {
                animation->Start();
            }
        }
        else if (mode == Mode::SEQUENCE)
        {
            auto animation = animations.front();

            if (animation != nullptr)
            {
                animation->Start();
            }
        }
    }

    [[nodiscard]] auto GetMode() const -> Mode { return mode; }

    void SetMode(Mode mode) { this->mode = mode; }

    [[nodiscard]] auto IsLooping() const -> Mode { return mode; }

    void SetIsLooping(bool looping) { this->looping = looping; }

    void AddAnimation(const std::shared_ptr<Animation> &animation)
    {
        animations.push_back(animation);
    }

    void Update(const double deltaTime) override
    {
        if (animations.empty())
        {
            return;
        }

        if (mode == Mode::PARALLEL)
        {
            for (auto &animation : animations)
            {
                if (animation->GetState() == Animation::State::RUNNING)
                {
                    animation->Tick(deltaTime);
                }
            }
        }
        else if (mode == Mode::SEQUENCE)
        {
            auto currentAnimation = animations[currentAnimationIndex];

            if (currentAnimation->GetState() == Animation::State::RUNNING)
            {
                if (currentAnimation->Tick(deltaTime) == 0)
                {
                    currentAnimationIndex++;

                    if (currentAnimationIndex >= animations.size())
                    {
                        if (looping)
                        {
                            currentAnimationIndex = 0;
                        }
                        else
                        {
                            return;
                        }
                    }

                    animations[currentAnimationIndex]->Start();
                }
            }
        }
    }
};

} // namespace Handcrank
