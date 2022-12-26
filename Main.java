public class  Main{
private static boolean isValidLuhn(String value) {
    int sum = Character.getNumericValue(value.charAt(value.length() - 1));
    int parity = value.length() % 2;
    for (int i = value.length() - 2; i >= 0; i--) {
        int summand = Character.getNumericValue(value.charAt(i));
        if (i % 2 == parity) {
            int product = summand * 2;
            summand = (product > 9) ? (product - 9) : product;
        }
        sum += summand;
    }
    return (sum % 10) == 0;
}

public static void main(String[] args)
{

 String num = "4276640540250042";
 boolean result = isValidLuhn(num);
 System.out.println(result);

}
}
