using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class Menu : MonoBehaviour {

    public int next_key = 0;
    public int prev_key = 0;
    public string next_page;
    public string prev_page;

    // Use this for initialization
    void Start () {
	
	}
	
	void Update () {

        switch (next_key)
        {
            case 1:
                if (Input.GetKeyDown(KeyCode.Space)) SceneManager.LoadScene(next_page);
                break;
            case 2:
                if (Input.GetKeyDown(KeyCode.Return)) SceneManager.LoadScene(next_page);
                break;
            case 3:
                if (Input.GetKeyDown(KeyCode.RightArrow)) SceneManager.LoadScene(next_page);
                break;
        }
        switch (prev_key)
        {
            case 1:
                if (Input.GetKeyDown(KeyCode.LeftArrow)) SceneManager.LoadScene(prev_page);
                break;
        }
    }
}
