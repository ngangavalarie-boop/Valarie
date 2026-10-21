#define _CRT_SECERU_NO_WARNINGS
#include <stdio.h>

int main() {
    int choice_regular, choice_parttime, choice_consultant;

    // Variables for Regular Employee
    float reg_salary = 0.0, reg_tax_rate = 0.0, reg_tax = 0.0, reg_net = 0.0;

    // Variables for Part-Time Employee
    float hours_worked = 0.0, pt_salary = 0.0, pt_tax = 0.0, pt_net = 0.0;
    float pt_rate = 1500.0; // 1500 per hour[span_3](start_span)[span_3](end_span)
    float pt_tax_rate = 0.33; // 33%[span_4](start_span)[span_4](end_span)

    // Variables for Consultant
    float const_fee = 0.0, const_tax = 0.0, const_net = 0.0;
    float const_tax_rate = 0.15; // 15%[span_5](start_span)[span_5](end_span)

    // Totals
    float total_gross = 0.0, total_tax = 0.0, total_net = 0.0;

    printf("=== Employee Salary and Tax Calculation System ===\n");
    printf("Does the employee work as a Regular Employee? (1 for Yes, 0 for No): ");
    scanf_s("%d", &choice_regular);

    if (choice_regular == 1) {
        printf("Enter Regular Employee Salary: ");
        scanf_s("%f", &reg_salary);

        // Determine Tax Rate based on Salary Range[span_6](start_span)[span_6](end_span)
        if (reg_salary >= 0 && reg_salary <= 14000) {
            reg_tax_rate = 0.18; // 18%[span_7](start_span)[span_7](end_span)
        }
        else if (reg_salary >= 14001 && reg_salary <= 24000) {
            reg_tax_rate = 0.25; // 25%[span_8](start_span)[span_8](end_span)
        }
        else if (reg_salary >= 24001 && reg_salary <= 45000) {
            reg_tax_rate = 0.27; // 27%[span_9](start_span)[span_9](end_span)
        }
        else if (reg_salary >= 45001 && reg_salary <= 100000) {
            reg_tax_rate = 0.30; // 30%[span_10](start_span)[span_10](end_span)
        }
        else {
            reg_tax_rate = 0.35; // 35% (Above 100,000)[span_11](start_span)[span_11](end_span)
        }

        reg_tax = reg_salary * reg_tax_rate; // PAYE = Tax rate x Salary[span_12](start_span)[span_12](end_span)
        reg_net = reg_salary - reg_tax;
    }

    printf("Does the employee work as a Part-Time Employee? (1 for Yes, 0 for No): ");
    scanf_s("%d", &choice_parttime);

    if (choice_parttime == 1) {
        printf("Enter total hours worked for Part-Time: ");
        scanf_s("%f", &hours_worked);

        pt_salary = hours_worked * pt_rate; // Rate of 1500 per hour[span_13](start_span)[span_13](end_span)
        pt_tax = pt_salary * pt_tax_rate;   // Part time tax = 33%[span_14](start_span)[span_14](end_span)
        pt_net = pt_salary - pt_tax;
    }

    printf("Does the employee provide Consultancy services? (1 for Yes, 0 for No): ");
    scanf_s("%d", &choice_consultant);

    if (choice_consultant == 1) {
        printf("Enter agreed contract price for Consultancy: ");
        scanf_s("%f", &const_fee);

        const_tax = const_fee * const_tax_rate; // Consultancy tax rate = 15%[span_15](start_span)[span_15](end_span)
        const_net = const_fee - const_tax;
    }

    // Calculate totals
    total_gross = reg_salary + pt_salary + const_fee;
    total_tax = reg_tax + pt_tax + const_tax;
    total_net = reg_net + pt_net + const_net;

    // Display Output Summary
    printf("\n========================================\n");
    printf("            SALARY & TAX SUMMARY        \n");
    printf("========================================\n");

    if (choice_regular == 1) {
        printf("Regular Employee Salary : %.2f\n", reg_salary);
        printf("Regular PAYE Tax (%.0f%%)  : %.2f\n", reg_tax_rate * 100, reg_tax);
    }

    if (choice_parttime == 1) {
        printf("Part-Time Salary        : %.2f\n", pt_salary);
        printf("Part-Time Tax (33%%)     : %.2f\n", pt_tax); 
    }

    if (choice_consultant == 1) {
        printf("Consultancy Fee         : %.2f\n", const_fee);
        printf("Consultancy Tax (15%%)   : %.2f\n", const_tax); 
    }

    printf("----------------------------------------\n");
    printf("Total Gross Income      : %.2f\n", total_gross);
    printf("Total Tax Deductions    : %.2f\n", total_tax);
    printf("Total Net Income        : %.2f\n", total_net);
    printf("========================================\n");

    return 0;
}