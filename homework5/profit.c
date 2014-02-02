#include <stdio.h>
#include <stdlib.h>

main(){
  int fixed_costs = 1400000, unit_cost = 22, selling_price = 50,gadget_produced = 5000000, gadget_sold = 2700000, gains = 0, losses = 0, net_profit = 0, final_profit = 0, final_fixed = 0, final_unit = 0, final_price = 0;
  srandom(time(0));
  int i;
  for(i = 0; i < 100000; ++i){
    fixed_costs = (int)random % (6601);
    fixed_costs = (1400 + fixed_costs) * 1000;
    unit_cost = (int)random % (9);
    unit_cost = unit_cost + 22;
    selling_price = (int)random % (21);
    selling_price = selling_price + 50;
    int rate = 0;
    rate += (fixed_costs - 1400000)/10000 * 2 + (unit_cost - 22) - (selling_price - 50) * 0.5;
    gains = gadget_sold * (1 + rate / 100.0) * (selling_price - unit_cost);
    losses = (gadget_produced - gadget_sold) * unit_cost + fixed_costs;
    net_profit = gains - losses;
    if(net_profit > final_profit){
      final_profit = net_profit;
      final_fixed = fixed_costs;
      final_unit = unit_cost;
      final_price = selling_price;
    }
  }
  printf("profit: %d;\nfixed costs: %d\nunit cost: %d\nprice: %d\n", final_profit, final_fixed, final_unit, final_price);
}
