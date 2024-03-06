#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <limits>

#define PI 3.141592
#define EARTH_RADIUS 6371.0
#define input std::cin >>
#define output std::cout <<

struct City // City structure
{
    std::string name;
    double lat; // Latitude
    double lon; // Longitude
};

double toRadians(double degree) // Convert degree to radians
{
    return degree * PI / 180.0;
}

double greatCircleDistance(const City& a, const City& b) // Calculate the great circle distance
{
    double deltaLon = b.lon - a.lon;
    double deltaSigma = acos(sin(a.lat) * sin(b.lat) + cos(a.lat) * cos(b.lat) * cos(deltaLon));
    return EARTH_RADIUS * deltaSigma; // Return the distance
}

void readCities(int N, std::vector<City>& cities, std::unordered_map<std::string, int>& cityIndex) // Read the cities
{
    for (int i = 0; i < N; ++i) // Iterating through the cities
    {
        input cities[i].name >> cities[i].lat >> cities[i].lon;
        cities[i].lat = toRadians(cities[i].lat); // Converting the latitude to radians
        cities[i].lon = toRadians(cities[i].lon); // Converting the longitude to radians
        cityIndex[cities[i].name] = i; // Adding the city to the index and it will look like this: {"cityName", index}
    }
}

void readFlights(int M, std::vector<std::vector<double>>& dist, const std::vector<City>& cities, const std::unordered_map<std::string, int>& cityIndex)
{
    for (int i = 0; i < M; ++i) // Iterating through the flights
    {
        std::string p, q; // Creating two strings p and q for the cities
        input p >> q;
        int u = cityIndex.at(p); // Get the index of the city p from the index map
        int v = cityIndex.at(q); // Get the index of the city q from the index map
        dist[u][v] = dist[v][u] = greatCircleDistance(cities[u], cities[v]); // Calculate the great circle distance between the two cities and add it to the distance matrix
    }
}

void floydWarshall(int N, std::vector<std::vector<double>>& dist) // Floyd Warshall algorithm (basic)
{
    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (dist[i][k] < std::numeric_limits<double>::max() && dist[k][j] < std::numeric_limits<double>::max())
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

std::pair<std::string, double> findMinCity(int N, const std::vector<std::vector<double>>& dist, const std::vector<City>& cities) // Finding the city with the minimum sum of distances
{
    double minSum = std::numeric_limits<double>::max();
    std::string minCity;
    for (int i = 0; i < N; ++i) // Iterating through the cities to find the minimum sum of distances
    {
        double sum = 0;
        for (int j = 0; j < N; ++j)
            sum += dist[i][j];
        if (sum < minSum)
        {
            minSum = sum;
            minCity = cities[i].name;
        }
    }
    return {minCity, minSum};
}

int main()
{
    int N, M; // Creating two integers N and M for the number of cities and flights
    input N >> M;
    std::vector<City> cities(N); // Creating a vector of cities
    std::unordered_map<std::string, int> cityIndex; // Creating an index map for the cities
    readCities(N, cities, cityIndex); // Read the cities
    std::vector<std::vector<double>> dist(N, std::vector<double>(N, std::numeric_limits<double>::max())); // Creating a distance matrix
    for (int i = 0; i < N; ++i) // Iterating through the cities
        dist[i][i] = 0;
    readFlights(M, dist, cities, cityIndex); // Read the flights and calculate the great circle distance
    floydWarshall(N, dist);
    auto [minCity, minSum] = findMinCity(N, dist, cities); // Find the city with the minimum sum of distances
    output minCity << " " << round(minSum);

}
