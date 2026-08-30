# vault-door-training
Category: Reverse Engineering
Difficulty: Easy
File Type: java
Tools Used: Terminal / Powershell to run script and any text editor (I used VSC)

## 1. Straight to the Flag
Opening the java file, we'll see a class that contains the flag inside one of its methods.

```
import java.util.*;

class VaultDoorTraining {
    public static void main(String args[]) {
        VaultDoorTraining vaultDoor = new VaultDoorTraining();
        Scanner scanner = new Scanner(System.in); 
        System.out.print("Enter vault password: ");
        String userInput = scanner.next();
	String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
	if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
	}
   }

    // The password is below. Is it safe to put the password in the source code?
    // What if somebody stole our source code? Then they would know what our
    // password is. Hmm... I will think of some ways to improve the security
    // on the other doors.
    //
    // -Minion #9567
    public boolean checkPassword(String password) {
        return password.equals("w4rm1ng_Up_w1tH_jAv4_000AXPNPN0i");
    }
}
```

<img width="673" height="92" alt="image" src="https://github.com/user-attachments/assets/e4af9da8-fc0a-4668-9053-b418f85187f3" />

Since, It looks like the password is just there, we'll just need to combine picoCTF with the flag inside of the bracket.

With that, we solved the challenge.
