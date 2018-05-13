package com.test;

import java.io.FileInputStream;
import java.util.Properties;

import org.fusesource.mqtt.client.QoS;
import org.fusesource.mqtt.client.Topic;

public class MQTTClientCfg {
	
	private String host;
	private int port;
	private String username;
	private String password;
	private Topic[] topics;
	
	public String getHost() {
		return host;
	}

	public void setHost(String host) {
		this.host = host;
	}

	public int getPort() {
		return port;
	}

	public void setPort(int port) {
		this.port = port;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public Topic[] getTopics() {
		return topics;
	}

	public void setTopics(Topic[] topics) {
		this.topics = topics;
	}
}
