#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        // Max heap -> stores fuel of stations we have passed
        priority_queue<int> pq;

        int fuel = startFuel;
        int prev = 0;
        int stops = 0;

        // Add destination as the final "station"
        stations.push_back({target, 0});

        for (auto &station : stations) {
            
            int position = station[0];
            int stationFuel = station[1];

            // Fuel needed to reach this station
            int distance = position - prev;

            fuel -= distance;

            // If we don't have enough fuel, refuel from
            // the largest fuel stations we have already passed
            while (fuel < 0 && !pq.empty()) {
                fuel += pq.top();
                pq.pop();
                stops++;
            }

            // Still cannot reach this station
            if (fuel < 0) {
                return -1;
            }

            // We have reached this station, so its fuel
            // is now available for future use
            pq.push(stationFuel);

            prev = position;
        }

        return stops;
    }
};