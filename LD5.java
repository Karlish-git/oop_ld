class Animal {

    private String name, nickname;
    private int birthYear;

    Animal() {
        this("Name", "Nickname", 0);
    }

    Animal(String n, String nick, int year) {
        name = n;
        nickname = nick;
        birthYear = year;
    }

    public String GetName() {
        return name;
    }

    public String GetNickName() {
        return nickname;
    }

    public int GetBirthYear() {
        return birthYear;
    }

    void SetName(String name) {
        this.name = name;
    }

    public void SetNickName(String nickname) {
        this.nickname = nickname;
    }

    public void SetBirthYear(int birthYear) {
        this.birthYear = birthYear;
    }

    @Override
    public String toString() {
        return "Name: " + name + " Nickname: " + nickname + " Birth year: " + birthYear;
    }

}


public class LD5 {

    public static void main(String[] args) {
        Animal a1 = new Animal("AA", "aa", 5);
        Animal a2 = new Animal();


        System.out.println(a1.toString());
        System.out.println(a1);
        System.out.println(a2);

        a2.SetName("B_");

        System.out.println(a2);
        System.out.println("\nPress \"Enter\" to finish program... ");

        try {
            System.in.read();
        }
        catch(java.io.IOException e) {
            System.out.println("Input/output exception.");
        }

    }
}
