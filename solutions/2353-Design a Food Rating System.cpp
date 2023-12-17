class FoodRatings {
private:
    unordered_map<string, pair<string, int>> foodToCuisineAndRating;
    map<string, map<int, set<string>, greater<int>>> cuisineToFood;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            foodToCuisineAndRating[foods[i]] = {cuisines[i], ratings[i]};
            cuisineToFood[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        auto& [cuisine, rating] = foodToCuisineAndRating[food];
        cuisineToFood[cuisine][rating].erase(food);
        if (cuisineToFood[cuisine][rating].empty()) {
            cuisineToFood[cuisine].erase(rating);
        }
        rating = newRating;
        cuisineToFood[cuisine][newRating].insert(food);
    }

    string highestRated(string cuisine) {
        return *cuisineToFood[cuisine].begin()->second.begin();
    }
};
