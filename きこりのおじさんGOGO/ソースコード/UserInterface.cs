using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class UserInterface : MonoBehaviour {

    public UnityEngine.UI.Text hourLabel,minuteLabel;
    private int time,hour,minute;

	// Use this for initialization
	void Start () {
        time = 1;
        hour = 12;
        minute = 0;
	}
	
	// Update is called once per frame
	void Update () {

        time++;
        if (time % 2 == 0) minute--;

        if (minute < 0)
        {
            minute = 59;
            hour--;
        }

        if (hour <= 0) hour = 0;

        if (hour == 0 && minute == 0) SceneManager.LoadScene("timeup");

        hourLabel.text = hour.ToString().PadLeft(2, '0');
        minuteLabel.text = minute.ToString().PadLeft(2, '0');
    }
}
