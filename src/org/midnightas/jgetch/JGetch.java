package org.midnightas.jgetch;

import java.io.IOException;

import cz.adamh.utils.NativeUtils;

public class JGetch {
	
	public static native int getch();
	
	static {
		try {
			NativeUtils.loadLibraryFromJar("/libjgetch.so");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
}
