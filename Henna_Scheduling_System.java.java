import java.util.ArrayList; // Import ArrayList class for storing appointments
import java.util.Scanner;   // Import Scanner class for user input

// Class representing an appointment
class Appointment {
    String clientName;  // Variable to store the client's name
    String dateTime;    // Variable to store the appointment date and time

    // Constructor to initialize an Appointment object
    public Appointment(String clientName, String dateTime) {
        this.clientName = clientName;  // Set the client's name
        this.dateTime = dateTime;      // Set the appointment date and time
    }

    // Method to return a string representation of the Appointment object
    @Override
    public String toString() {
        return "Client: " + clientName + ", Date & Time: " + dateTime;  // Format the appointment details
    }
}

// Class for handling appointment scheduling
class AppointmentScheduler {
    private ArrayList<Appointment> appointments = new ArrayList<>();  // List to store all appointments

    // Method to add a new appointment
    public void addAppointment(String clientName, String dateTime) {
        appointments.add(new Appointment(clientName, dateTime));  // Create a new Appointment and add it to the list
        System.out.println("Appointment added for " + clientName + " on " + dateTime);  // Inform the user
    }

    // Method to view all scheduled appointments
    public void viewAppointments() {
        if (appointments.isEmpty()) {  // Check if there are no appointments
            System.out.println("No appointments scheduled.");  // Inform the user
        } else {
            for (Appointment app : appointments) {  // Iterate through the list of appointments
                System.out.println(app);  // Print each appointment's details
            }
        }
    }
}

// Main class to interact with the user
public class HennaSchedulingSystem {
    public static void main(String[] args) {
        AppointmentScheduler scheduler = new AppointmentScheduler();  // Create an instance of AppointmentScheduler
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for user input
        String choice;  // Variable to store the user's menu choice

        do {
            // Display the menu options
            System.out.println("\nHenna Appointment Scheduler");
            System.out.println("1. Add Appointment");
            System.out.println("2. View Appointments");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextLine();  // Read the user's choice

            switch (choice) {  // Handle the user's menu choice
                case "1":
                    // Add an appointment
                    System.out.print("Enter client's name: ");
                    String name = scanner.nextLine();  // Read the client's name
                    System.out.print("Enter appointment date and time: ");
                    String dateTime = scanner.nextLine();  // Read the appointment date and time
                    scheduler.addAppointment(name, dateTime);  // Add the appointment
                    break;
                case "2":
                    // View all appointments
                    scheduler.viewAppointments();  // Display all scheduled appointments
                    break;
                case "3":
                    // Exit the program
                    System.out.println("Exiting system.");  // Inform the user
                    break;
                default:
                    // Handle invalid menu choices
                    System.out.println("Invalid choice. Try again.");  // Inform the user
            }
        } while (!choice.equals("3"));  // Repeat until the user chooses to exit

        scanner.close();  // Close the Scanner object
    }
}
