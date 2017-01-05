

MotionSensor::MotionSensor(int id,I2CCom& i2c,Camera& cam,Light& light):Sensor(id,i2c,cam),light(light){}

MotionSensor::Check(){
	if(GetValue()){
		SetActive();
		light.Set_Light(true);
		return true;
	}
	return Alive();
}