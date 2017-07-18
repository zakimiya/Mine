using UnityEngine;
using System.Collections;

public class GameOver : MonoBehaviour {

    public UnityEngine.UI.Text scoreLabel;

    // Use this for initialization
    void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {

        scoreLabel.text = PlayerController.score.ToString();

    }
}
