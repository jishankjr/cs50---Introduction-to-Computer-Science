# List of coin values in dollars
dollars = [0.01, 0.05, 0.1, 0.25]


def formula(change):
    coin = 0  # Initialize coin counter

    # Calculate the number of quarters (0.25) needed
    while change >= 0.25:
        change -= dollars[3]  # Subtract the value of a quarter
        coin += 1  # Increment coin count
        change = round(change, 2)  # Round change to avoid floating-point errors

    # Calculate the number of dimes (0.10) needed
    while change >= 0.1:
        change -= dollars[2]  # Subtract the value of a dime
        coin += 1  # Increment coin count
        change = round(change, 2)  # Round change to avoid floating-point errors

    # Calculate the number of nickels (0.05) needed
    while change >= 0.05:
        change -= dollars[1]  # Subtract the value of a nickel
        coin += 1  # Increment coin count
        change = round(change, 2)  # Round change to avoid floating-point errors

    # Calculate the number of pennies (0.01) needed
    while change >= 0.01:
        change -= dollars[0]  # Subtract the value of a penny
        coin += 1  # Increment coin count
        change = round(change, 2)  # Round change to avoid floating-point errors

    print(f"{coin}")  # Output the total number of coins used


while True:
    try:
        # Get user input and convert to float
        change = float(input("Change = "))

        # If change is positive, proceed to calculate coins
        if change > 0:
            formula(change)
            break
        # If change is negative, reject input
        elif change < 0:
            print("Not accepted! Please enter a positive value.")
        # If change is zero, reject input
        else:
            print("Not accepted! Please enter a value greater than 0.")
    except ValueError:
        # Handle non-numeric input
        print("Not accepted! Please enter a numeric value.")