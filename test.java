import java.util.ArrayDeque;
import java.util.Arrays;

public class Solution {

  public static int[] solution(int area) {
    int[] finalAr = {};
    ArrayDeque<Integer> areaQueue = new ArrayDeque<>();

    panelCalc(area, areaQueue);

    finalAr = new int[areaQueue.size()];
    for (int i = areaQueue.size() - 1; i >= 0; i--) {
      finalAr[i] = areaQueue.pop();
    }

    return finalAr;
  }

  public static int panelCalc(int area, ArrayDeque<Integer> aq) {
    int panelArea = 0;

    if (area >= 1 && area <= 1000000) {
      int temp = (int) Math.sqrt(area);
      if (temp <= 0) {
        return panelArea;
      } else {
        panelArea = (int) Math.pow(temp, 2);
        int nextArea = area - panelArea;
        panelCalc(nextArea, aq);
        aq.add(panelArea);
      }
    }
    return panelArea;
  }
}