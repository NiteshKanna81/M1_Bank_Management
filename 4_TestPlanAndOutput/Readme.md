# Test Plan and Test Ouput

| **Test ID** | **HLT ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**PASS/FAIL**  |    
|-------------|-----|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  T_01|H_01| Provide required details for Register Account| Register| Successfully Registered | Successfully Registered| PASS |
|  T_02|H_01| When Invalid Details is entered as input|  Entered invalid input | Entered Details is invalid | PASS |
|  T_03|H_02| Display the  details of user action|  Enter choice | Display action | Display action | PASS |
|  T_04|H_02| View Account Details | enter choice | Display Account Details | Displaied account details| PASS |
|  T_05|H_03| Deposite Amount | Amount to deposited | Total account balance | Total account balance | PASS |
|  T_06|H_04| WithDraw Amount | Amount to withdraw | Total account balance | Total account balance | PASS |
|  T_07|H_03| Transfer amount | Amount to transfer, Account number to transfer to| Transfered Succesfully,Account balance | Transfered Succesfully,Account balance | PASS |
|  T_08|H_03| Change password | enter new passowrd | Updated Successfully | Updated Successfully | PASS |
