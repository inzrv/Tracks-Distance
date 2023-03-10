#include "core_structs.h"
#include "draw.h"
#include "distances.h"
#include "track_generator.h"
#include "read_write.h"

#include <opencv2/core.hpp>
#include <vector>

int main() {
    std::vector<Track> tracks;
    getTracksFromCSV("../test/csv/close_tracks.csv", tracks);
    cv::Mat img;
    getTracksImg(img, tracks);
    cv::imwrite("../test/img/close_tracks.png", img);

    std::cout << "Frechet, euclidean" << std::endl;
    for (size_t i = 0; i < tracks.size() - 1; ++i) {
        for (size_t j = i + 1; j < tracks.size(); ++j) {
            std::cout << "F_e("<< i + 1 << ", " << j + 1 << ") = " <<
                      frechet(tracks[i], tracks[j], Metric::euclidean) << std::endl;
        }
    }
    std::cout << std::endl;


    std::cout << "Frechet, XYT" << std::endl;
    for (size_t i = 0; i < tracks.size() - 1; ++i) {
        for (size_t j = i + 1; j < tracks.size(); ++j) {
            std::cout << "F_xyt("<< i + 1 << ", " << j + 1 << ") = " <<
                      frechet(tracks[i], tracks[j], Metric::XYT) << std::endl;
        }
    }
    std::cout << std::endl;


}

/* Tracks from tracks.csv
 * std::vector<Track> tracks;
 * getTracksFromCSV("../../test/tracks.csv", tracks);
 */

/* Generate and save random track
 * Track randTrack;
 * generateRandomTrack(randTrack, 20, 1500, 1000);
 * cv::Mat img;
 * std::vector<Track> randTrackVec = {randTrack};
 * getTracksImg(img, randTrackVec);
 * cv::imwrite("../../test/img/rand_track.png", img);
 * writeTracksToCSV(randTrackVec, "../../test/rand_track.csv");
 */

/* Distances for tracks.csv
 *  std::vector<Track> tracks;
    getTracksFromCSV("../test/csv/tracks.csv", tracks);

    cv::Mat img;
    getTracksImg(img, tracks);
    cv::imwrite("../test/img/tracks.png", img);

    std::cout << "Frechet, euclidean" << std::endl;
    for (size_t i = 0; i < tracks.size() - 1; ++i) {
        for (size_t j = i + 1; j < tracks.size(); ++j) {
            std::cout << "F_e("<< i + 1 << ", " << j + 1 << ") = " <<
            frechet(tracks[i], tracks[j], Metric::euclidean) << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "Frechet, XYT" << std::endl;
    for (size_t i = 0; i < tracks.size() - 1; ++i) {
        for (size_t j = i + 1; j < tracks.size(); ++j) {
            std::cout << "F_t("<< i + 1 << ", " << j + 1 << ") = " <<
                     frechet(tracks[i], tracks[j], Metric::XYT) << std::endl;
        }
    }
    std::cout << std::endl;
*/