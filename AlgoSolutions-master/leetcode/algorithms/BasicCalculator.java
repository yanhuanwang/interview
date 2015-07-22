/*
 * Implement a basic calculator to evaluate a simple expression string.

 * The expression string may contain open ( and closing parentheses ), 
 * the plus + or minus sign -, non-negative integers and empty spaces .
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 */
public class BasicCalculator {

    //TODO
    // fix bug -->  2 * 2 * 2 * 2 / 4 = 0

    public int calculate(String s) {
        Stack<Character> stackOpt = new Stack<Character>();
        Stack<Integer> stackNum = new Stack<Integer>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if ('0' <= c && c <= '9') {
                int num = 0;
                while (i < s.length() && '0' <= s.charAt(i) && s.charAt(i) <= '9') {
                    num = num * 10 + s.charAt(i) - '0';
                    i++;
                }
                i--;
                stackNum.push(num);
            } else if (c == '(' || c == '*' || c == '/') {
                stackOpt.push(c);
            } else if (c == ')') {
                while (!stackOpt.isEmpty() && stackOpt.peek() != '(') {
                    calc(stackOpt, stackNum);
                }
                stackOpt.pop(); // pop '('.
            } else if (c == '+' || c == '-') {
                if (!stackOpt.isEmpty() && (stackOpt.peek() == '*' || stackOpt.peek() == '/')) {
                    Stack<Character> stackOptTmp = new Stack<Character>();
                    Stack<Integer> stackNumTmp = new Stack<Integer>();
                    while (!stackOpt.isEmpty() && (stackOpt.peek() == '*' || stackOpt.peek() == '/')) {
                        stackOptTmp.push(stackOpt.pop());
                        stackNumTmp.push(stackNum.pop());
                    }
                    stackNumTmp.push(stackNum.pop());
                    while (!stackOptTmp.isEmpty()) {
                        calc(stackOptTmp, stackNumTmp);
                    }
                    stackNum.push(stackNumTmp.pop());
                }
                while (!stackOpt.isEmpty() && (stackOpt.peek() == '*' || stackOpt.peek() == '/')) {
                    calc(stackOpt, stackNum);
                }
                stackOpt.push(c);
            }
        }
        while (!stackOpt.isEmpty()) {
            calc(stackOpt, stackNum);
        }
        return stackNum.pop();
    }

    public int calculate(String s) {
        List<Character> optList = new LinkedList<Character>();
        List<Integer> numList = new LinkedList<Character>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if ('0' <= c && c <= '9') {
                int num = 0;
                while (i < s.length() && '0' <= s.charAt(i) && s.charAt(i) <= '9') {
                    num = num * 10 + s.charAt(i) - '0';
                    i++;
                }
                i--;
                numList.add(num);
            } else if (c == '(' || c == '*' || c == '/') {
                optList.add(c);
            } else if (c == ')') {
                int j = i;
                for (; optList.get(j) != '('; j--);
                optList.remove(j);
                int k = numList.size();
                for (; numList.size() - k < optList.size() - j; k--);
                while (j < optList.size()) {
                    char opt = optList.remove();
                    int num1 = numList.get(k - 1);
                    int num2 = numList.get(k);
                    numList.insert(k, calc(num1, num2, opt));
                }
            } else if (c == '+' || c == '-') {

            }
        }
        while (optList.size() != 0) {
            char opt = optList.remove(0);
            int num1 = numList.remove(0);
            int num2 = numList.remove(0);
            numList.insert(0, calc(num1, num2, opt);
        }
    }

    public void calc(List<Character> optList, List<Integer> numList) {
        int num2 = numList.remove(list.size() - 1);
        int num1 = numList.remove(list.size() - 1);
        numList.add(calc(num1, num2, optList.remove(optList.size() - 1));
    }

    public int calc(int num1, int num2, char operator) {
        switch (operator) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
            default:
                return Integer.parseInt(null);
        }
    }


    public void calc(Stack<Character> stackOpt, Stack<Integer> stackNum) {
        int num2 = stackNum.pop();
        int num1 = stackNum.pop();
        stackNum.push(calc(num1, stackOpt.pop(), num2));
    }

    public int calc(int num1, char operator, int num2) {
        switch (operator) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
            default:
                return Integer.parseInt(null);
        }
    }





    public int calculate(String s) {
        List<Integer> numList = new LinkedList<Integer>();
        List<Character> optList = new LinkedList<Character>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if ('0' <= c && c <= '9') {
                int num = 0;
                while (i < s.length() && '0' <= s.charAt(i) && s.charAt(i) <= '9') {
                    num = num * 10 + s.charAt(i) - '0';
                    i++;
                }
                i--;
                numList.add(num);
            } else if (c == '(') {
                optList.add(c);
            } else if (c == '+' || c == '-') {
                optList.add(c);
            } else if (c == ')') {
                int j = optList.size();
                while (optList.get(j) != '(') {
                    j--;
                }
                int 
            }
        }
    }

}
