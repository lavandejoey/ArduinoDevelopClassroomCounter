int minLight = 150,
photoValue1 = 0,
photoValue2 = 0,
photoPin1 = 2,
photoPin2 = 3;
int pNum = 0;
int count(void) {
	photoValue1 = analogRead(photoPin1);
	photoValue2 = analogRead(photoPin2);//两个光敏电阻进行光强采集
	//调试用：Serial.println(photocellValue1);Serial.println(photocellValue2);

	while (photoValue1 > minLight && photoValue2 > minLight) {
		photoValue1 = analogRead(photoPin1);
		photoValue2 = analogRead(photoPin2);
	}//当两个光敏所采集的光强值大于临界值时，光敏电阻持续采集光强

	if (photoValue1 < minLight) {
		while (photoValue2 > minLight) {
			photoValue2 = analogRead(photoPin2);
		}
		while (photoValue1 < minLight) {
			photoValue1 = analogRead(photoPin1);
		}
		while (photoValue2 < minLight) {
			photoValue2 = analogRead(photoPin2);
		}
		pNum++;
	}//实现当人走进教室，人数加1
	if (photoValue2 < minLight) {
		while (photoValue1 > minLight) {
			photoValue1 = analogRead(photoPin1);
		}
		while (photoValue2 < minLight) {
			photoValue2 = analogRead(photoPin2);
		}
		while (photoValue1 < minLight) {
			photoValue1 = analogRead(photoPin1);
		}
		pNum--;
	}//实现当人走出教室，人数减1

	Serial.println(pNum);//output the number of people
	Serial.println(photoValue1);//output the value of
	Serial.println(photoValue2);
	Serial.println("——-");
	delay(10);
}