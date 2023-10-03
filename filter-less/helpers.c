#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get average of colors
            float avg = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3);

            // Assign that average to all colors
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Define sepia colors
            int sepiaRed = round(0.393 * image[i][j].rgbtRed
                                 + 0.769 * image[i][j].rgbtGreen
                                 + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed
                                   + 0.686 * image[i][j].rgbtGreen
                                   + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed
                                  + 0.534 * image[i][j].rgbtGreen
                                  + 0.131 * image[i][j].rgbtBlue);

            // Cap color values at 255 if higher
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Replacing original colors with sepia
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Those arrays are going to store pixels in inverted order
    int reflectedRed[height][width];
    int reflectedGreen[height][width];
    int reflectedBlue[height][width];

    for (int i = 0; i < height; i++)
    {
        int k = 0;

        for (int j = width - 1; j >= 0; j--)
        {
            // Storing pixels in inverted order
            reflectedRed[i][k] = image[i][j].rgbtRed;
            reflectedGreen[i][k] = image[i][j].rgbtGreen;
            reflectedBlue[i][k] = image[i][j].rgbtBlue;

            k++;
        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Inverting original pixels
            image[i][j].rgbtRed = reflectedRed[i][j];
            image[i][j].rgbtGreen = reflectedGreen[i][j];
            image[i][j].rgbtBlue = reflectedBlue[i][j];
        }
    }

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Those arrays are going to store original pixel colors
    int originalRed[height][width];
    int originalGreen[height][width];
    int originalBlue[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Saving original pixel values into 2D arrays
            originalRed[i][j] = image[i][j].rgbtRed;
            originalGreen[i][j] = image[i][j].rgbtGreen;
            originalBlue[i][j] = image[i][j].rgbtBlue;
        }
    }

    float sumRed;
    float sumGreen;
    float sumBlue;

    int counter;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;

            counter = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                // Those loops below represents iterating through all pixels around
                // and image[i][j] pixel itself
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        sumRed += originalRed[k][l];
                        sumGreen += originalGreen[k][l];
                        sumBlue += originalBlue[k][l];

                        counter++;
                    }
                }
            }

            // Bluring pixel
            image[i][j].rgbtRed = round(sumRed / counter);
            image[i][j].rgbtGreen = round(sumGreen / counter);
            image[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }
}
