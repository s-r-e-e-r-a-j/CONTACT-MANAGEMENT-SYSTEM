#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contact_count = 0;

void add_contact(const char *name, const char *phone) {
    if (contact_count < MAX_CONTACTS) {
        strcpy(contacts[contact_count].name, name);
        strcpy(contacts[contact_count].phone, phone);
        contact_count++;
        printf("Contact added: %s, %s\n", name, phone);
    } else {
        printf("Contact list is full!\n");
    }
}

void view_contacts() {
    if (contact_count == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("Contact List:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d: %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void delete_contact(int index) {
    if (index < 1 || index > contact_count) {
        printf("Invalid contact number!\n");
        return;
    }
    for (int i = index - 1; i < contact_count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contact_count--;
    printf("Contact deleted.\n");
}

int main() {
    int choice;
    char name[NAME_LENGTH], phone[PHONE_LENGTH];

    while (1) {
        printf("\n1. Add Contact\n2. View Contacts\n3. Delete Contact\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter phone number: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0; // Remove newline
                add_contact(name, phone);
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                printf("Enter contact number to delete: ");
                int contact_number;
                scanf("%d", &contact_number);
                delete_contact(contact_number);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}