#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Author: NFN Rokayah
// 24SP-CSC134-N801: C++
// Final Programming Exam


// Constants for streaming rates
const double TIDAL_RATE = 0.01250;
const double AMAZON_RATE = 0.00402;
const double APPLE_RATE = 0.00735;
const double SPOTIFY_RATE = 0.00437;
const double YOUTUBE_RATE = 0.00069;

// Function prototypes
string getLabelType();
int getNumSongs();
long generateSongStreams(string labelType);
void streamingBreakdown(long tidalStreams[], long amazonStreams[], long appleStreams[], long spotifyStreams[], long youtubeStreams[], int numSongs);

int main() {
    // Seed for random number generator
    srand(time(0));
    
    // Get Menu choice from user input
    string labelType = getLabelType();
    
    // Get Number of Songs from user input
    int numSongs = getNumSongs();
    
    // Declare and populate arrays
    long tidalStreams[numSongs];
    long amazonStreams[numSongs];
    long appleStreams[numSongs];
    long spotifyStreams[numSongs];
    long youtubeStreams[numSongs];
    
    for (int i = 0; i < numSongs; ++i) {
        tidalStreams[i] = generateSongStreams(labelType);
        amazonStreams[i] = generateSongStreams(labelType);
        appleStreams[i] = generateSongStreams(labelType);
        spotifyStreams[i] = generateSongStreams(labelType);
        youtubeStreams[i] = generateSongStreams(labelType);
    }
    
    // Display streaming breakdown
    streamingBreakdown(tidalStreams, amazonStreams, appleStreams, spotifyStreams, youtubeStreams, numSongs);
    
    return 0;
}

string getLabelType() {
    string labelType;
    cout << "Choose from one of the following Music Label Types:" << endl;
    cout << "  A. Independent Label" << endl;
    cout << "  B. Major Label" << endl;
    cout << "Enter your choice (A or B): ";
    cin >> labelType;
    // Validate input
    while (labelType != "A" && labelType != "a" && labelType != "B" && labelType != "b") {
        cout << "ERROR: INVALID MENU CHOICE. TRY AGAIN." << endl;
        cout << "\nEnter your choice (A or B): ";
        cin >> labelType;
    }
    return labelType;
}

int getNumSongs() {
    int numSongs;
    cout << "How many songs will be uploaded to the streaming platforms (Min: 1 - Max: 9)? ";
    cin >> numSongs;
    // Validate input
    while (numSongs < 1 || numSongs > 9) {
        cout << "ERROR: INVALID NUMBER OF SONGS. TRY AGAIN." << endl;
        cout << "\nHow many songs will be uploaded to the streaming platforms (Min: 1 - Max: 9)? ";
        cin >> numSongs;
    }
    return numSongs;
}

long generateSongStreams(string labelType) {
    long streams;
    
    // Generate streams based on label type
    if (labelType == "A" || labelType == "a" ) { // Independent Label
        streams = rand() % (1000000 - 10000 + 1) + 10000; // Random number between 10,000 and 1,000,000
    } else if (labelType == "B" || labelType == "b" ) { // Major Label
        streams = rand() % (50000000 - 100000 + 1) + 100000; // Random number between 100,000 and 50,000,000
    }
    return streams;
}

void streamingBreakdown(long tidalStreams[], long amazonStreams[], long appleStreams[], long spotifyStreams[], long youtubeStreams[], int numSongs) {
    long totalTidalStreams = 0, totalAmazonStreams = 0, totalAppleStreams = 0, totalSpotifyStreams = 0, totalYoutubeStreams = 0, totalStreams = 0;
    double totalTidalEarnings = 0, totalAmazonEarnings = 0, totalAppleEarnings = 0, totalSpotifyEarnings = 0, totalYoutubeEarnings = 0, totalEarnings = 0;
    
    cout << endl;
    cout << setw(9) << "Song #";
    cout << setw(15) << "Tidal";
    cout << setw(15) << "Amazon";
    cout << setw(15) << "Apple Music";
    cout << setw(15) << "Spotify";
    cout << setw(15) << "YouTube" << endl;
    
    for (int i = 0; i < numSongs; ++i) {
        cout << setw(8) << "Song #" << (i+1);
        cout << setw(15) << tidalStreams[i];
        cout << setw(15) << amazonStreams[i];
        cout << setw(15) << appleStreams[i];
        cout << setw(15) << spotifyStreams[i];
        cout << setw(15) << youtubeStreams[i] << endl;
        
        // Update totals
        totalTidalStreams += tidalStreams[i];
        totalAmazonStreams += amazonStreams[i];
        totalAppleStreams += appleStreams[i];
        totalSpotifyStreams += spotifyStreams[i];
        totalYoutubeStreams += youtubeStreams[i];
        
        // Calculate earnings
        totalTidalEarnings += tidalStreams[i] * TIDAL_RATE;
        totalAmazonEarnings += amazonStreams[i] * AMAZON_RATE;
        totalAppleEarnings += appleStreams[i] * APPLE_RATE;
        totalSpotifyEarnings += spotifyStreams[i] * SPOTIFY_RATE;
        totalYoutubeEarnings += youtubeStreams[i] * YOUTUBE_RATE;
        
        // Calculate total streams
        totalStreams += tidalStreams[i] + amazonStreams[i] + appleStreams[i] + spotifyStreams[i] + youtubeStreams[i];
    }
    
    // Display stream totals
    cout << "\nStream Totals:" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < numSongs; ++i) {
        cout << "Song #" << (i+1) << setw(28) << "Total Streams: " << (tidalStreams[i] + amazonStreams[i] + appleStreams[i] + spotifyStreams[i] + youtubeStreams[i]) << endl;
    }
    
    // Display platform totals and earnings
    cout << "\nPlatform Totals:"  << setw(42) << "Platform Earnings:" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Tidal" << setw(20) << totalTidalStreams << setw(27) << "Tidal Earnings" << "$" << fixed << setprecision(2) << totalTidalEarnings << endl;
    cout << left << setw(20) << "Amazon Music" << setw(20) << totalAmazonStreams << setw(27) << "Amazon Earnings" << "$" << totalAmazonEarnings << endl;
    cout << left << setw(20) << "Apple Music" << setw(20) << totalAppleStreams << setw(27) << "Apple Earnings" << "$" << totalAppleEarnings << endl;
    cout << left << setw(20) << "Spotify" << setw(20) << totalSpotifyStreams << setw(27) << "Spotify Earnings" << "$" << totalSpotifyEarnings << endl;
    cout << left << setw(20) << "YouTube" << setw(20) << totalYoutubeStreams << setw(27) << "YouTube Earnings" << "$" << totalYoutubeEarnings << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    
    // Calculate total earnings
    totalEarnings = totalTidalEarnings + totalAmazonEarnings + totalAppleEarnings + totalSpotifyEarnings + totalYoutubeEarnings;
    // Display total streams and earnings
    cout << left << setw(20) << "Total Streams:" << setw(20) << totalStreams << setw(27) << "Total Earnings:" << "$" << totalEarnings << endl;

    // Calculate average streams and earnings per platform
    double avgStreamsPerPlatform = totalStreams / 5.0;
    double avgEarningsPerPlatform = totalEarnings / 5.0;
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "Avg. Streams per Platform:   " << avgStreamsPerPlatform << endl;
    cout << "Avg. Earnings Per Platform:   $" << avgEarningsPerPlatform << endl;
    cout << "---------------------------------------" << endl;
}
