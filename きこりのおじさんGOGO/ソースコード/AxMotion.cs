using UnityEngine;
using System.Collections;

public class AxMotion : MonoBehaviour {

    private int vanish;

    // Use this for initialization
    void Start () {
        vanish = 0;
	}
	
	// Update is called once per frame
	void Update ()
    {
        Vector3 pos = transform.position;

        if (vanish < 0) vanish = -1;

        if (vanish == 0)
        {
            pos.x = Random.Range(-20, 20);
            pos.z = Random.Range(-20, 20);
        }
        if (vanish > 0) pos.y = -1;
        else pos.y = 0.1f;

        vanish--;

        transform.position = pos;
    }

    void OnTriggerEnter(Collider hit)
    {

        // 接触対象はPlayerタグですか？
        if (hit.CompareTag("Player"))
        {
            vanish = 180;
        }
    }
}
