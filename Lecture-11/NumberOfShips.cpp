class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (topRight[0] < bottomLeft[0]
                || topRight[1] < bottomLeft[1] ||
                !sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        // if we have reached on to a single point where
        // topLeft and BottomRight both the co-ordinates are on the same point
        // there we will have the ship for sure
        if (topRight[0] == bottomLeft[0] and topRight[1] == bottomLeft[1]) {
            return 1;
        }

        // Break the problem into 4 smaller problems
        int mx = (topRight[0] + bottomLeft[0]) / 2;
        int my = (topRight[1] + bottomLeft[1]) / 2;
        vector<int> mid;
        mid.push_back(mx);
        mid.push_back(my);
        int a = topRight[0];
        int b = topRight[1];

        int x = bottomLeft[0];
        int y = bottomLeft[1];
        return countShips(sea, mid, bottomLeft) +
               countShips(sea, {a, my}, {mx + 1, y}) +
               countShips(sea, topRight, {mx + 1, my + 1}) +
               countShips(sea, {mx, b}, {x, my + 1});
    }
};