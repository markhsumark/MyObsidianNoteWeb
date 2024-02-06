

solution（程式）
Barber
while(true){
wait(customer);
wait(mutex);
waiting = waiting - 1;
signal(Barber); //表示我有空了，叫醒客人
signal(mutex);
"理髮"
}
務必先測同步再測互斥
Customer
wait(mutex);
if(waiting < n ){
waiting = waiting + 1;
signal(mutex);
signal(customer);
wait(Barber);  //理髮師在忙的話就會卡在這
“被理髮中()”
}else{   //滿座，不入店內
signal(mutex);
}