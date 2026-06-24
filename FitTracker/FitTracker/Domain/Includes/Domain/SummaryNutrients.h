#pragma once

namespace Domain {
    class SummaryNutrients final {
    public:
        SummaryNutrients() = default;
        ~SummaryNutrients() = default;

        void setFats(float value);
        float getFats() const;

        void setProteins(float value);
        float getProteins() const;

        void setCarbohydrates(float value);
        float getCarbohydrates() const;

        float getCalories() const;

    private:
        float fats_ = 0.f;              // Value of the summary fats of anything (meal or a day goal)
        float proteins_ = 0.f;          // Value of the summary proteins of anything (meal or a day goal)
        float carbohydrates_ = 0.f;     // Value of the summary carbohydrates of anything (meal or a day goal)
    };
} // namespace Domain