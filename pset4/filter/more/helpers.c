#include "helpers.h"
#include <math.h>

int cap(int number);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float total = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            float average = round(total / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        //We only have to reach the half of each row
        for (int j = 0; j < width / 2; j++)

        {
            //Any swap implementation would be okay
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Make container for original image
    RGBTRIPLE old_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Fill original image matrix
            old_image[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;

            float redTotal = 0;
            float greenTotal = 0;
            float blueTotal = 0;

            //For each pixel...
            //Check to see if each possible surrounding pixel actually exists in matrix

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {

                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }

                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    //If it doesn't, then, do nothing.
                    //If it does, add their color to the corresponding variable, and increment counter;

                    redTotal += old_image[i + k][j + l].rgbtRed;
                    greenTotal += old_image[i + k][j + l].rgbtGreen;
                    blueTotal += old_image[i + k][j + l].rgbtBlue;
                    counter++;
                }
            }

            //Counter will tell us how many elements actually are included in the total of each color, so we can get the average properly.
            image[i][j].rgbtRed = round(redTotal / counter);
            image[i][j].rgbtGreen = round(greenTotal / counter);
            image[i][j].rgbtBlue = round(blueTotal / counter);
        }
    }
    return;
}

int cap(int number)
{
    if (number > 255)
    {
        return 255;
    }
    return number;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Make container for original image
    RGBTRIPLE old_image[height][width];

    //Define multipliers
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Fill original image matrix
            old_image[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float gx_red = 0;
            float gx_green = 0;
            float gx_blue = 0;

            float gy_red = 0;
            float gy_green = 0;
            float gy_blue = 0;

            int red = 0;
            int green = 0;
            int blue = 0;

            //For each pixel...
            //Check to see if each possible surrounding pixel actually exists in matrix

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {

                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }

                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    //If it doesn't, then, do nothing.
                    //If it does, add their color to the corresponding variable for gx and gy multiplying by correct value for each matrix

                    gx_red += old_image[i + k][j + l].rgbtRed * gx[k + 1][l + 1];
                    gx_green += old_image[i + k][j + l].rgbtGreen * gx[k + 1][l + 1];
                    gx_blue += old_image[i + k][j + l].rgbtBlue * gx[k + 1][l + 1];

                    gy_red += old_image[i + k][j + l].rgbtRed * gy[k + 1][l + 1];
                    gy_green += old_image[i + k][j + l].rgbtGreen * gy[k + 1][l + 1];
                    gy_blue += old_image[i + k][j + l].rgbtBlue * gy[k + 1][l + 1];

                }
            }

            red = sqrt(pow(gx_red, 2) + pow(gy_red, 2));
            green = sqrt(pow(gx_green, 2) + pow(gy_green, 2));
            blue = sqrt(pow(gx_blue, 2) + pow(gy_blue, 2));

            //Counter will tell us how many elements actually are included in the total of each color, so we can get the average properly.
            image[i][j].rgbtRed = cap(round(red));
            image[i][j].rgbtGreen = cap(round(green));
            image[i][j].rgbtBlue = cap(round(blue));
        }
    }
    return;
}