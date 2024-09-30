#!/bin/bash

# Define rates for different types of cars
car_rate=35
van_rate=55
suv_rate=40

while true; do
    echo "Enter the type of car (car, van, suv) or 'Exit' to terminate:"
    read car_type
    
    # Check if the user wants to exit
    if [ "$car_type" == "Exit" ]; then
        echo "Exiting the program."
        exit 0
    fi

    # Check for valid car types
    if [ "$car_type" != "car" ] && [ "$car_type" != "van" ] && [ "$car_type" != "suv" ]; then
        echo "Invalid car type. Please enter 'car', 'van', or 'suv'."
        continue
    fi

    echo "Enter the number of rental days:"
    read days
    
    # Check if days is a valid number
    if ! [[ "$days" =~ ^[0-9]+$ ]]; then
        echo "Invalid number of days. Please enter a positive integer."
        continue
    fi

    # Calculate and display the cost based on car type
    case "$car_type" in
        car)
            cost=$((days * car_rate))
            ;;
        van)
            cost=$((days * van_rate))
            ;;
        suv)
            cost=$((days * suv_rate))
            ;;
    esac

    echo "The total cost for renting a $car_type for $days days is: \$${cost}"
done
