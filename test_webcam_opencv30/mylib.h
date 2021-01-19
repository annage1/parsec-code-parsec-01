
#ifndef MYLIB_H
#define MYLIB_H

#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Lors de la compil on compil le nano cpp puis on compil le .h on déclare des fonction PUIS on RENTRE DANS le mylib.cpp ON INCLUDE => RENTRER A NOUVEAU DANS LE .H ET DU COUP ON REDEFINIT toutes LES FONCTIONdu .h d'ou le ifndef si c pas défini on rentre dedans

cv::Mat seuillage_rouge_jaune(cv::Mat image_in);
cv::Mat seuillage_vert_cyan(cv::Mat image_in);
cv::Mat seuillage_bleu_violet(cv::Mat image_in);
cv::Mat detection_contour(cv::Mat image_in);
cv::Mat gaussien(cv::Mat image_in);
cv::Mat noir_blanc(cv::Mat image_in);
cv::Mat ghost_mode(cv::Mat image_in);

#endif
