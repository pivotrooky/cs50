#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Cap value at 255
int cap(int n)
{
    if (n > 255)
    {
        n = 255;
    }

    return n;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float r = image[i][j].rgbtRed;
            float g = image[i][j].rgbtGreen;
            float b = image[i][j].rgbtBlue;

            float avg = round((r + g + b) / 3.0);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;

        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float r = image[i][j].rgbtRed;
            float g = image[i][j].rgbtGreen;
            float b = image[i][j].rgbtBlue;


            image[i][j].rgbtRed = cap(round(.393 * r + .769 * g + .189 * b));
            image[i][j].rgbtGreen = cap(round(.349 * r + .686 * g + .168 * b));
            image[i][j].rgbtBlue = cap(round(.272 * r + .534 * g + .131 * b));

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int temp[3] = {image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue};

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtBlue = temp[2];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    float r[9];
    float g[9];
    float b[9];
    RGBTRIPLE tempimage[height][width];


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i == 0) && (j == 0)) //Superior/Left
            {
                r[0] = image[i][j].rgbtRed;
                r[1] = image[i + 1][j].rgbtRed;
                r[2] = image[i][j + 1].rgbtRed;
                r[3] = image[i + 1][j + 1].rgbtRed;

                tempimage[i][j].rgbtRed = round((r[0] + r[1] + r[2] + r[3]) / 4.0);

                g[0] = image[i][j].rgbtGreen;
                g[1] = image[i + 1][j].rgbtGreen;
                g[2] = image[i][j + 1].rgbtGreen;
                g[3] = image[i + 1][j + 1].rgbtGreen;

                tempimage[i][j].rgbtGreen = round((g[0] + g[1] + g[2] + g[3]) / 4.0);

                b[0] = image[i][j].rgbtBlue;
                b[1] = image[i + 1][j].rgbtBlue;
                b[2] = image[i][j + 1].rgbtBlue;
                b[3] = image[i + 1][j + 1].rgbtBlue;

                tempimage[i][j].rgbtBlue = round((b[0] + b[1] + b[2] + b[3]) / 4.0);
            }

            else if ((i == 0) && (j == width - 1)) //Superior/Right
            {
                r[0] = image[i][j - 1].rgbtRed;
                r[1] = image[i][j].rgbtRed;
                r[2] = image[i + 1][j - 1].rgbtRed;
                r[3] = image[i + 1][j].rgbtRed;

                tempimage[i][j].rgbtRed = round((r[0] + r[1] + r[2] + r[3]) / 4.0);

                g[0] = image[i][j - 1].rgbtGreen;
                g[1] = image[i][j].rgbtGreen;
                g[2] = image[i + 1][j - 1].rgbtGreen;
                g[3] = image[i + 1][j].rgbtGreen;

                tempimage[i][j].rgbtGreen = round((g[0] + g[1] + g[2] + g[3]) / 4.0);

                b[0] = image[i][j - 1].rgbtBlue;
                b[1] = image[i][j].rgbtBlue;
                b[2] = image[i + 1][j - 1].rgbtBlue;
                b[3] = image[i + 1][j].rgbtBlue;

                tempimage[i][j].rgbtBlue = round((b[0] + b[1] + b[2] + b[3]) / 4.0);
            }

            else if (i == 0) //Superior/Middle
            {
                r[0] = image[i][j - 1].rgbtRed;
                r[1] = image[i][j].rgbtRed;
                r[2] = image[i][j + 1].rgbtRed;
                r[3] = image[i + 1][j - 1].rgbtRed;
                r[4] = image[i + 1][j].rgbtRed;
                r[5] = image[i + 1][j + 1].rgbtRed;

                tempimage[i][j].rgbtRed = round((r[0] + r[1] + r[2] + r[3] + r[4] + r[5]) / 6.0);

                g[0] = image[i][j - 1].rgbtGreen;
                g[1] = image[i][j].rgbtGreen;
                g[2] = image[i][j + 1].rgbtGreen;
                g[3] = image[i + 1][j - 1].rgbtGreen;
                g[4] = image[i + 1][j].rgbtGreen;
                g[5] = image[i + 1][j + 1].rgbtGreen;

                tempimage[i][j].rgbtGreen = round((g[0] + g[1] + g[2] + g[3] + g[4] + g[5]) / 6.0);

                b[0] = image[i][j - 1].rgbtBlue;
                b[1] = image[i][j].rgbtBlue;
                b[2] = image[i][j + 1].rgbtBlue;
                b[3] = image[i + 1][j - 1].rgbtBlue;
                b[4] = image[i + 1][j].rgbtBlue;
                b[5] = image[i + 1][j + 1].rgbtBlue;

                tempimage[i][j].rgbtBlue = round((b[0] + b[1] + b[2] + b[3] + b[4] + b[5]) / 6.0);
            }

            else if ((i == height - 1) && (j == 0)) //Inferior/Left
            {
                r[0] = image[i - 1][j].rgbtRed;
                r[1] = image[i - 1][j + 1].rgbtRed;
                r[2] = image[i][j].rgbtRed;
                r[3] = image[i][j + 1].rgbtRed;

                tempimage[i][j].rgbtRed = round((r[0] + r[1] + r[2] + r[3]) / 4.0);

                g[0] = image[i - 1][j].rgbtGreen;
                g[1] = image[i - 1][j + 1].rgbtGreen;
                g[2] = image[i][j].rgbtGreen;
                g[3] = image[i][j + 1].rgbtGreen;

                tempimage[i][j].rgbtGreen = round((g[0] + g[1] + g[2] + g[3]) / 4.0);

                b[0] = image[i - 1][j].rgbtBlue;
                b[1] = image[i - 1][j + 1].rgbtBlue;
                b[2] = image[i][j].rgbtBlue;
                b[3] = image[i][j + 1].rgbtBlue;

                tempimage[i][j].rgbtBlue = round((b[0] + b[1] + b[2] + b[3]) / 4.0);
            }

            else if ((i == height - 1) && (j == width - 1)) //Inferior/Right
            {
                r[0] = image[i - 1][j - 1].rgbtRed;
                r[1] = image[i - 1][j].rgbtRed;
                r[2] = image[i][j - 1].rgbtRed;
                r[3] = image[i][j].rgbtRed;

                tempimage[i][j].rgbtRed = round((r[0] + r[1] + r[2] + r[3]) / 4.0);

                g[0] = image[i - 1][j - 1].rgbtGreen;
                g[1] = image[i - 1][j].rgbtGreen;
                g[2] = image[i][j - 1].rgbtGreen;
                g[3] = image[i][j].rgbtGreen;

                tempimage[i][j].rgbtGreen = round((g[0] + g[1] + g[2] + g[3]) / 4.0);

                b[0] = image[i - 1][j - 1].rgbtBlue;
                b[1] = image[i - 1][j].rgbtBlue;
                b[2] = image[i][j - 1].rgbtBlue;
                b[3] = image[i][j].rgbtBlue;

                tempimage[i][j].rgbtBlue = round((b[0] + b[1] + b[2] + b[3]) / 4.0);
            }

            else if (i == height - 1) //Inferior/Middle
            {

                r[0] = image[i - 1][j - 1].rgbtRed;
                r[1] = image[i - 1][j].rgbtRed;
                r[2] = image[i - 1][j + 1].rgbtRed;
                r[3] = image[i][j - 1].rgbtRed;
                r[4] = image[i][j].rgbtRed;
                r[5] = image[i][j + 1].rgbtRed;

                tempimage[i][j].rgbtRed = round((r[0] + r[1] + r[2] + r[3] + r[4] + r[5]) / 6.0);

                g[0] = image[i - 1][j - 1].rgbtGreen;
                g[1] = image[i - 1][j].rgbtGreen;
                g[2] = image[i - 1][j + 1].rgbtGreen;
                g[3] = image[i][j - 1].rgbtGreen;
                g[4] = image[i][j].rgbtGreen;
                g[5] = image[i][j + 1].rgbtGreen;

                tempimage[i][j].rgbtGreen = round((g[0] + g[1] + g[2] + g[3] + g[4] + g[5]) / 6.0);

                b[0] = image[i - 1][j - 1].rgbtBlue;
                b[1] = image[i - 1][j].rgbtBlue;
                b[2] = image[i - 1][j + 1].rgbtBlue;
                b[3] = image[i][j - 1].rgbtBlue;
                b[4] = image[i][j].rgbtBlue;
                b[5] = image[i][j + 1].rgbtBlue;

                tempimage[i][j].rgbtBlue = round((b[0] + b[1] + b[2] + b[3] + b[4] + b[5]) / 6.0);
            }

            else if (j == 0) //Middle/Left
            {
                r[0] = image[i - 1][j].rgbtRed;
                r[1] = image[i - 1][j + 1].rgbtRed;
                r[2] = image[i][j].rgbtRed;
                r[3] = image[i][j + 1].rgbtRed;
                r[4] = image[i + 1][j].rgbtRed;
                r[5] = image[i + 1][j + 1].rgbtRed;

                tempimage[i][j].rgbtRed = round((r[0] + r[1] + r[2] + r[3] + r[4] + r[5]) / 6.0);

                g[0] = image[i - 1][j].rgbtGreen;
                g[1] = image[i - 1][j + 1].rgbtGreen;
                g[2] = image[i][j].rgbtGreen;
                g[3] = image[i][j + 1].rgbtGreen;
                g[4] = image[i + 1][j].rgbtGreen;
                g[5] = image[i + 1][j + 1].rgbtGreen;

                tempimage[i][j].rgbtGreen = round((g[0] + g[1] + g[2] + g[3] + g[4] + g[5]) / 6.0);

                b[0] = image[i - 1][j].rgbtBlue;
                b[1] = image[i - 1][j + 1].rgbtBlue;
                b[2] = image[i][j].rgbtBlue;
                b[3] = image[i][j + 1].rgbtBlue;
                b[4] = image[i + 1][j].rgbtBlue;
                b[5] = image[i + 1][j + 1].rgbtBlue;

                tempimage[i][j].rgbtBlue = round((b[0] + b[1] + b[2] + b[3] + b[4] + b[5]) / 6.0);
            }

            else if (j == width - 1) //Middle/Right
            {
                r[0] = image[i - 1][j - 1].rgbtRed;
                r[1] = image[i - 1][j].rgbtRed;
                r[2] = image[i][j - 1].rgbtRed;
                r[3] = image[i][j].rgbtRed;
                r[4] = image[i + 1][j - 1].rgbtRed;
                r[5] = image[i + 1][j].rgbtRed;

                tempimage[i][j].rgbtRed = round((r[0] + r[1] + r[2] + r[3] + r[4] + r[5]) / 6.0);

                g[0] = image[i - 1][j - 1].rgbtGreen;
                g[1] = image[i - 1][j].rgbtGreen;
                g[2] = image[i][j - 1].rgbtGreen;
                g[3] = image[i][j].rgbtGreen;
                g[4] = image[i + 1][j - 1].rgbtGreen;
                g[5] = image[i + 1][j].rgbtGreen;

                tempimage[i][j].rgbtGreen = round((g[0] + g[1] + g[2] + g[3] + g[4] + g[5]) / 6.0);

                b[0] = image[i - 1][j - 1].rgbtBlue;
                b[1] = image[i - 1][j].rgbtBlue;
                b[2] = image[i][j - 1].rgbtBlue;
                b[3] = image[i][j].rgbtBlue;
                b[4] = image[i + 1][j - 1].rgbtBlue;
                b[5] = image[i + 1][j].rgbtBlue;

                tempimage[i][j].rgbtBlue = round((b[0] + b[1] + b[2] + b[3] + b[4] + b[5]) / 6.0);
            }

            else //Middle/Middle
            {
                r[0] = image[i - 1][j - 1].rgbtRed;
                r[1] = image[i][j - 1].rgbtRed;
                r[2] = image[i + 1][j - 1].rgbtRed;
                r[3] = image[i - 1][j].rgbtRed;
                r[4] = image[i][j].rgbtRed;
                r[5] = image[i + 1][j].rgbtRed;
                r[6] = image[i - 1][j + 1].rgbtRed;
                r[7] = image[i][j + 1].rgbtRed;
                r[8] = image[i + 1][j + 1].rgbtRed;

                tempimage[i][j].rgbtRed = round((r[0] + r[1] + r[2] + r[3] + r[4] + r[5] + r[6] + r[7] + r[8]) / 9.0);

                g[0] = image[i - 1][j - 1].rgbtGreen;
                g[1] = image[i][j - 1].rgbtGreen;
                g[2] = image[i + 1][j - 1].rgbtGreen;
                g[3] = image[i - 1][j].rgbtGreen;
                g[4] = image[i][j].rgbtGreen;
                g[5] = image[i + 1][j].rgbtGreen;
                g[6] = image[i - 1][j + 1].rgbtGreen;
                g[7] = image[i][j + 1].rgbtGreen;
                g[8] = image[i + 1][j + 1].rgbtGreen;

                tempimage[i][j].rgbtGreen = round((g[0] + g[1] + g[2] + g[3] + g[4] + g[5] + g[6] + g[7] + g[8]) / 9.0);

                b[0] = image[i - 1][j - 1].rgbtBlue;
                b[1] = image[i][j - 1].rgbtBlue;
                b[2] = image[i + 1][j - 1].rgbtBlue;
                b[3] = image[i - 1][j].rgbtBlue;
                b[4] = image[i][j].rgbtBlue;
                b[5] = image[i + 1][j].rgbtBlue;
                b[6] = image[i - 1][j + 1].rgbtBlue;
                b[7] = image[i][j + 1].rgbtBlue;
                b[8] = image[i + 1][j + 1].rgbtBlue;

                tempimage[i][j].rgbtBlue = round((b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6] + b[7] + b[8]) / 9.0);
            }

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempimage[i][j];
        }

    }
    return;
}
