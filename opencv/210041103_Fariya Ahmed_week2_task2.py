import cv2
import numpy as np

def detect_red_and_white_regions(image):
    # Converting the image from BGR to HSV color space
    converted_hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

    # Define the lower and upper bounds for colors in HSV
    lower_bound_for_red1 = np.array([0, 50, 50])
    upper_bound_for_red1 = np.array([100, 255, 255])
    lower_bound_for_red2 = np.array([170, 50, 50])
    upper_bound_for_red2 = np.array([180, 255, 255])
    # Create masks to isolate red regions
    mask_red_region1 = cv2.inRange(converted_hsv_image, lower_bound_for_red1, upper_bound_for_red1)
    mask_red_region2 = cv2.inRange(converted_hsv_image, lower_bound_for_red2, upper_bound_for_red2)
    # join my masks
    mask_red_region = mask_red_region1 + mask_red_region2

    lower_bound_for_white = np.array([0, 0, 100])
    upper_bound_for_white = np.array([180, 30, 255])

    # Create mask to isolate white regions
    mask_white_region = cv2.inRange(converted_hsv_image, lower_bound_for_white, upper_bound_for_white)

    # Create a blank canvas for displaying red and white regions
    result_image = np.zeros_like(image)
    result_image[mask_red_region != 0] = [0, 0, 255]  # Set red regions as red in the result image
    result_image[mask_white_region != 0] = [255, 255, 255]  # Set white regions as white in the result image

    # Display the red and white regions
    cv2.imshow("Red and White Regions", result_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
def analyze_goat(image_array):
    # Find the minimum and maximum pixel values in the image
    min_value = np.min(image_array)
    max_value = np.max(image_array)

    # Find the average pixel value in the image
    average_value = np.mean(image_array)

    # Count the total number of non-zero (foreground) and zero (background) pixels in the image
    foreground_pixels = np.count_nonzero(image_array)
    background_pixels = image_array.size - foreground_pixels

    # Convert the 2D grayscale image to 3-channel grayscale image for display purposes
    grayscale_image = cv2.cvtColor(image_array, cv2.COLOR_GRAY2BGR)

    # Display the information on the image
    cv2.putText(grayscale_image, f"Min: {min_value}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
    cv2.putText(grayscale_image, f"Max: {max_value}", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
    cv2.putText(grayscale_image, f"Avg: {average_value:.2f}", (10, 90), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
    cv2.putText(grayscale_image, f"Foreground Pixels: {foreground_pixels}", (10, 120), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
    cv2.putText(grayscale_image, f"Background Pixels: {background_pixels}", (10, 150), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)

    # Display the image with information
    cv2.imshow("Processed Image", grayscale_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == "__main__":
    # Loading the image
    image_path = "GOAT.jpg"
    color_image = cv2.imread(image_path)
    #Displaying the main image
    cv2.imshow( "Main Image",color_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    # Task 1: Detecting red and white regions
    detect_red_and_white_regions(color_image)
    # Changing the image to grayscale
    grayscale_image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    # Task 2 to 5: Analyzing grayscale image and displaying information
    analyze_goat(grayscale_image)
