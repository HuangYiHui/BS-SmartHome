package bs.pi.gateway.msg;

public class OutSensorValuesComingMsg implements IMsg {

	public final static String MSG_NAME = "OutSensorValuesComingMsg";
	
	private float temperature;
	private float humidity;
	private float heat;
	private float dustConcentration;
	private float lightIntensity;
	private float solidHumidity;
	
	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return MSG_NAME;
	}

	public float getTemperature() {
		return temperature;
	}

	public void setTemperature(float temperature) {
		this.temperature = temperature;
	}

	public float getHumidity() {
		return humidity;
	}

	public void setHumidity(float humidity) {
		this.humidity = humidity;
	}

	public float getHeat() {
		return heat;
	}

	public void setHeat(float heat) {
		this.heat = heat;
	}

	public float getDustConcentration() {
		return dustConcentration;
	}

	public void setDustConcentration(float dustConcentration) {
		this.dustConcentration = dustConcentration;
	}

	public float getLightIntensity() {
		return lightIntensity;
	}

	public void setLightIntensity(float lightIntensity) {
		this.lightIntensity = lightIntensity;
	}

	public float getSolidHumidity() {
		return solidHumidity;
	}

	public void setSolidHumidity(float solidHumidity) {
		this.solidHumidity = solidHumidity;
	}
}
