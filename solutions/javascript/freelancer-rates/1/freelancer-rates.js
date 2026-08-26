
export function dayRate(ratePerHour) {
  return 8 * ratePerHour;
}

export function daysInBudget(budget, ratePerHour) {
  return Math.floor(budget / (ratePerHour * 8));
}

export function priceWithMonthlyDiscount(ratePerHour, numDays, discount) {
  let months = Math.floor(numDays/22);
  let price =  months * ratePerHour * 8 * (1-discount)*22;
  let extraWorkPrice = (numDays % 22) * 8 * ratePerHour;
  return Math.ceil(price + extraWorkPrice);
}
